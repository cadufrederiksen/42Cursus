/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:02:06 by carmarqu          #+#    #+#             */
/*   Updated: 2023/04/25 17:48:14 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst2 == NULL && src2 == NULL)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
		{
			dst2[len] = src2[len];
		}
	}
	else
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}

/* int main()
{
	char	orig[];
	size_t	n;

    orig[] = "hola";
    char dest[] = "carloss"; 
    char dest1[] = "carloss";   
    n = 2 ;
    printf("%s \n", ft_memmove(dest, orig, n));
    printf("%s", memmove(dest1, orig, n));
}
 */