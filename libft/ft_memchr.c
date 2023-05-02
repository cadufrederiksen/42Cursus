/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:54:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/04/25 13:48:47 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;
	unsigned int	i;

	b = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)b[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/* int main()
{
    unsigned char s[] = "carlos";
    int c = 'a';
    size_t n = 2;
    printf("%s \n", ft_memchr(s, c, n));
    printf("%s", memchr(s, c, n));
} */