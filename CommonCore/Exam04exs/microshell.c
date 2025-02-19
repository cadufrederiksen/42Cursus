#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>


void err(char *str)
{
	while (*str)
		write(2, str++, 1);//fd 2 que eh o de erro
}

int cd(char **argv, int i)
{
	if (i != 2)//se houver mais de um argumetno, RETURN 1 com ERR
		return err("error: cd: bad arguments\n"), 1;
	if (chdir(argv[1]) == -1)// se falhar, RETURN 1 com ERR
		return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"), 1;
	return 0;//RETURN 0 se tudo ok
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))// se houver um pipe e uma dessa funcoes falhar, exit
		err("error: fatal\n"), exit(1);
}

int	exec(char **argv, int i, char **envp)
{
	int has_pipe, fd[2], pid, status;

	has_pipe = argv[i] && !strcmp(argv[i], "|");//flag para se existe pipe

	if (!has_pipe && !strcmp(*argv, "cd"))//apenas um cd basico
		return cd(argv, i);

	if (has_pipe && pipe(fd) == -1)//se houver pipe e esse falhar
		err("error: fatal\n"), exit(1);

	if ((pid = fork()) == -1)//se o fork falhar
		err("error: fatal\n"), exit(1);
	if (!pid)// se o pid for 0 (processo filho)
	{
		argv[i] = 0;//argv[i] eh apagado pois eh quando se deve parar
		set_pipe(has_pipe, fd, 1);//redireciona a saida padrao do processo filho para descritor de escrita para o pipe, permitindo o pai ler
		if (!strcmp(*argv, "cd"))//se for cd executa ele ja com comando exit
			exit(cd(argv, i));
		execve(*argv, argv, envp);//execve do argv* atual;
		err("error: cannot execute "), err(*argv), err("\n"), exit(1);
	}
	waitpid(pid, &status, 0);//espera o processo filho terminar
	set_pipe(has_pipe, fd, 0);//redireciona a entrada padrao do processo filho para o fd de leitura, permitindo o pai escrever
	return WIFEXITED(status) && WEXITSTATUS(status);//check da saida do processo filho
}

int main(int argc, char **argv, char **envp)
{
	int i = 0, status = 0;

	while (argv[i])
	{
		argv += i + 1;//skipa os argvs lido e o executavel
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))//enquanto existir e nao for | nem ;
			i++;
		if (i)
			status = exec(argv, i, envp);//se existe se executa e guarda status de saida
	}
	return status;
}
