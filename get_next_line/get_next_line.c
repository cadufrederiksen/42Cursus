/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:04 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/24 16:07:18 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *get_line(int fd, char *buff)
{
	char *aux;
	int i;
	int btread;

	aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	i = 0;
	btread = 1;
	while(aux[i] != '\n' || aux[i] != 0)
		i++;
	while (btread > 0)
	{
		
	}

	free(aux);
	return(buff);
} 

char	*get_next_line(int fd)
{
	static char* buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = (char *)ft_calloc(1, sizeof(char));
	buff = get_line(fd, buff);
	return(buff);
}

int	main(void)
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
