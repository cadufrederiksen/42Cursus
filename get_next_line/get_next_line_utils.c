/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/26 16:03:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (ptr == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		ptr[i + x] = s2[x];
		x++;
	}
	ptr[i + x] = '\0';
	return (ptr);
	free(ptr);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			x;
	char			*sub;

	x = 0;
	i = start;
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		sub[0] = 0;
		return(sub);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL || s == NULL)
		return (0);
	while (x < len)
	{
		sub[x] = s[i];
		i++;
		x++;
	}
	sub[x] = '\0';
	return (sub);
}