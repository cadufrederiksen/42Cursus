/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:50:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/04/25 14:47:24 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	dstlen;

	dstlen = ft_strlen(dst);
	x = 0;
	if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = dstlen;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[x] != '\0')
		{
			dst[i] = src[x];
			x++;
			i++;
		}
		dst[i] = '\0';
	}
	return (dstlen + ft_strlen(src));
}

/* int main()
{
    char dst[] = "pqrstuvwxyz";
    char src[] = "abcd";
    size_t i;
    i = 20;
    printf("%zu \n", ft_strlcat(dst, src, i));
}  */