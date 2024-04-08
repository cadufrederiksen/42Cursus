/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:22:47 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:18 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Essa função funciona perfeitamente mas a moulinette não aceitou

size_t	check_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	x;
	size_t	equal;

	equal = 0;
	i = 0;
	while (i == equal && s1[i] != '\0')
	{
		x = 0;
		while (set[x] != '\0')
		{
			if (s1[i] == set[x])
				equal++;
			x++;
		}
		i++;
	}
	return (equal);
}

size_t	check_end(char const *s1, char const *set)
{
	size_t	len;
	size_t	x;
	size_t	equal;
	size_t	out;

	out = 0;
	len = ft_strlen(s1) - 1;
	equal = 0;
	while (out == equal && s1[out] != '\0')
	{
		x = 0;
		while (set[x] != '\0')
		{
			if (set[x] == s1[len])
				equal++;
			x++;
		}
		len--;
		out++;
	}
	return (equal);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	x;
	size_t	ptr_len;

	if (!s1 || !set)
		return (NULL);
	x = check_start(s1, set);
	ptr_len = ft_strlen(s1) - check_end(s1, set) - x;
	i = 0;
	if (ft_strlen(s1) == check_start(s1, set))
		return (ft_calloc(1, 1));
	ptr = (char *)malloc((ptr_len) + 1);
	if (!ptr)
		return (NULL);
	while (i < ptr_len)
	{
		ptr[i] = s1[x];
		i++;
		x++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* int main() 
{
	char s1[] = "aabcabcholaquetalbcab";
	char set[] = "abc";

	printf("%s\n", ft_strtrim(s1, set));
	printf("%zu\n", check_end(s1, set));
	printf("%zu\n", ft_strlen(s1));
	printf("%zu\n", check_start(s1, set));
	return(0);
}  */