/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:04 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/13 15:53:38 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *stack, char *tmp)
{
	char	*aux;

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = 0;
	}
	if (!stack)
		return (NULL);
	aux = ft_strjoin(stack, tmp);
	free(stack);
	return (aux);
}

char	*ft_get_line(char *stack)
{
	char	*line;
	size_t	i;

	if (!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*aux;
	char	*rest;
	int		i;

	i = 0;
	rest = ft_strchr(stack, '\n');
	if (!rest)
	{
		free(stack);
		return (NULL);
	}
	rest++;
	aux = malloc(sizeof(char) * (ft_strlen(rest) + 1));
	if (!aux)
		return (NULL);
	while (*rest != '\0')
	{
		aux[i] = *rest;
		i++;
		rest++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		btread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	btread = 1;
	while (btread > 0)
	{
		btread = read(fd, tmp, BUFFER_SIZE);
		if (btread < 0)
			return (free(stack), stack = NULL, NULL);
		tmp[btread] = '\0';
		stack = ft_join(stack, tmp);
		if (!stack)
			return (NULL);
		if (ft_strchr(stack, '\n'))
			break ;
	}
	line = ft_get_line(stack);
	stack = update_stack(stack);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}
 */