/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:04 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/26 16:06:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *stack, char *tmp)
{
	char	*aux;

	if (!stack)
	{
		stack = malloc(1); //"inicializar stack se não estiver inicializado"
		stack[0] = 0;
	}
	aux = ft_strjoin(stack, tmp); // colocar o contéudo de read dentro de stack;
	free(stack);                  //free o contéudo que tinha em stack antes
	return (aux);                 //devolve o novo contéudo de stack
}

char	*update_stack(char *stack, char *line)
{
	char	*aux;

	aux = ft_substr(stack, ft_strlen(line), (ft_strlen(stack) //preciso mecher aqui
				- ft_strlen(line))); //teoricamente guarda o que restou de stack
	free(stack);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char *stack; //onde é guardado todo o contéudo lido(estática)
	char *tmp;          //onde se armazena o que for lido por read
	char *line;         //linha devolvida pela função
	ssize_t btread;     //quantidade de bt lidos por read
	
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	btread = 1;        // para forçar entrar no bucle
	while (btread > 0)
	//dentro de um bucle porque eu preciso ler o txt mais de uma vez
	{
		btread = read(fd, tmp, BUFFER_SIZE);
			//guarda o que for lido em tmp e quanto foi lido em btread
		tmp[btread] = 0;                    
			//última posiçñao recebe NULL para saber onde é o final
		stack = ft_join(stack, tmp);        
			//add o contéudo lido de tmp em stack
		if (ft_strchr(stack, '\n'))
			break ;
				//parar o bucle se já houver um salto de linha dentro de stack
	}
	line = ft_substr(stack, 0, ft_strchr(stack,'\n') + 1);
		//teoricamente receberia toda a linha com salto de linha
	stack = update_stack(stack, line);                                                     
		//elimina a linha lido de stack e aramazena o resto
	return (line);
}

/* int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
} */