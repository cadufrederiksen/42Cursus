/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:25:54 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/02 12:57:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int countword(char const *s, char c)
{
	size_t i;
	size_t counter;

	counter = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		counter++;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
	}
	return(counter);
}

char **ft_split(char const *s, char c)
{
	int count_word;
	char **ptr;
	size_t x;
	size_t len;

	x = 0;
	
	count_word = countword(s, c);
	ptr = (char**)malloc(count_word + 1);
	if (!ptr)
		return(0);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while(*s != c)	
			{
				s++;
				len++;
			}
				ptr[x] = ft_substr(s, 0, len);
				x++;
		}
	}	
	ptr[count_word] = NULL;
	return(ptr); 
} 

int main()
{
	char s[] = "hola que tal";
	char c = ' ';
	int x;

	x = 0;
	while (x <= countword(s, c))
 	{
		printf("%s\n", ft_split(s, c)[x]);
		x++;
	}
	return(0);
}