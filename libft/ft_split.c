/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:25:54 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/02 17:10:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countword(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
			i++;
		else
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	count_word;
	size_t	x;
	size_t	len;
	char	**ptr;

	count_word = countword(s, c);
	if (!s)
		return(0);
	ptr = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!ptr)
		return (0);
	x = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*(s + len) != c && *(s + len) != 0)
				len++;
			if (x < count_word)
			{
				ptr[x] = ft_substr(s, 0, len);
				x++;
			}
			s += len;
		}
	}
	ptr[x] = NULL;
	return (ptr); 
}

/* int	main(void)
{
	char	s[]= "hola que tal";
	char	c;
	char **result;
	c = ' ';

	result = ft_split(s,c);
	

		printf("%s\n", result[0]);
		printf("%s\n", result[1]);
		printf("%s\n", result[2]);
		printf("%s", result[3]);
	return (0);
}
 */