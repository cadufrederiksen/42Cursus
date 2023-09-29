/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:42:17 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/26 10:13:20 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)&s[i]);
}

/* int main()
{
    char array[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
    int c = '\0';

    printf("%s", ft_strchr(array, c));
    //printf("%s", strchr(array, c));
}  */