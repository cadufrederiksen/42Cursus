/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:25:22 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/26 10:44:46 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return ((char *)&s[i]);
		i++;
	}
	return ((char *)&s[i]);
}

int main()
{ 
	char array[] = "hola tudo bem";
	printf("%zu", (ft_strlen(array) - ft_strlen(ft_strchr(array, '\n'))));
	return(0);
}