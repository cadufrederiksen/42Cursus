/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:00:36 by carmarqu          #+#    #+#             */
/*   Updated: 2023/04/25 15:29:38 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (source == NULL && dest == NULL)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

/* int	main(void)
{
		unsigned char src[] = "";
	unsigned char dest[] = "";
	size_t n = 11;
	printf("%s \n", ft_memcpy(((void *)0), ((void *)0), 3));
	printf("%s", memcpy(dest, src, n));*/