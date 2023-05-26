/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:04 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/26 09:40:48 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_join(char *stack, char *tmp)
{
	char *aux;

	if(!stack)
	{
		stack = malloc(1);//"inicializar stack se não estiver inicializado"
		stack[0] = '\0';
	}
	aux = ft_strjoin(stack, tmp);// colocar o contéudo de read dentro de stack;
	free(stack);//free o contéudo que tinha em stack antes
	return(aux);//devolve o novo contéudo de stack
}

char	*get_next_line(int fd)
{
	static char *stack; //onde é guardado todo o contéudo lido(estática)
	char *tmp[BUFFER_SIZE + 1];//onde se armazena o que for lido por read
	char *line; //linha devolvida pela função
	ssize_t btread; //quantidade de bt lidos por read
	
	btread = 1;// para forçar entrar no bucle
	while(btread > 0)//dentro de um bucle porque eu preciso ler o txt mais de uma vez
	{
		btread = read(fd, tmp, BUFFER_SIZE); //guarda o que for lido em tmp e quanto foi lido em btread
		tmp[btread] = '\0'; //última posiçñao recebe NULL para saber onde é o final
		stack = ft_join(stack, tmp); //add o contéudo lido de tmp em stack
		if
	}
	return(stack);

}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s",  line);
	free(line);
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s",  line);
	free(line);
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s",  line);
	return (0);
} 