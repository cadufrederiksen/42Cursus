/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:04 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/25 16:00:29 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_saved(char *saved)
{
	char	*aux;
	char	*p;
	int		i;

	i = 0;
	p = ft_strchr(saved, '\n');
	if (!p)
	{
		free(saved);
		return (NULL);
	}
	p++;
	aux = malloc(sizeof(char) * ft_strlen(p) + 1);
	while (*p != '\0')
	{
		aux[i] = *p;
		p++;
		i++;
	}
	aux[i] = '\0';
	free(saved);
	return (aux);
}

char	*create_line(char *saved)
{
	char	*line;
	int		i;

	if (!saved || !*saved)
		return (NULL);
	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	if (saved[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_join(char *saved, char *tmp)
{
	char	*aux;

	if (!saved)
		saved = ft_calloc(1, 1);
	if (!saved)
		return (0);
	aux = ft_strjoin(saved, tmp);
	free(saved);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		btread;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	btread = 1;
	while (btread > 0)
	{
		btread = read(fd, tmp, BUFFER_SIZE);
		if (btread < 0)
			return (free(saved), saved = NULL, NULL);
		tmp[btread] = '\0';
		saved = ft_join(saved, tmp);
		if (!saved)
			return (NULL);
		if (ft_strchr(saved, '\n'))
			break ;
	}
	//até aqui temos saved com tudo que foi lido, precisamos fazer uma linha
	line = create_line(saved);
	saved = new_saved(saved);
	return (line);
}

/* int main()
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
}  */