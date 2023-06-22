/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:25:54 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/22 17:45:46 by carmarqu         ###   ########.fr       */
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

void	free_cpp(char **arr, int words)
{
	while (words-- > 0)
	{
		free(arr[words]);
	}
	free(arr);
}

char	**splitting(const char *s, char **ptr, char c, size_t count_word)
{
	size_t	x;
	size_t	len;

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
				if(!ptr[x])
					return(free_cpp(ptr, x), NULL);
				x++;
			}
			s += len;
		}
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	count_word;
	char	**ptr;

	count_word = countword(s, c);
	if (!s)
		return (0);
	ptr = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!ptr)
		return (0);
	splitting(s, ptr, c, count_word);
	ptr[count_word] = NULL;
	return (ptr);
}

/* int	main(void)
{
	char	c;
	int		x;

	char	s[]= "hola, que, tal ywdw wdadwd wadaw";
	
	c = ' ';
	x = 0;
	while (x <= countword(s, c))
	{
		printf("%s\n", ft_split(s,c)[x]);
		x++;
	}
	printf("%d", countword(s, c));
	return (0);
}
 */