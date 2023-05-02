/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:16:24 by carmarqu          #+#    #+#             */
/*   Updated: 2023/04/23 16:28:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		x = 0;
		while (haystack[i + x] == needle[x] && (i + x) < len)
		{
			if (needle[x + 1] == '\0')
				return ((char *)haystack + i);
			x++;
		}
		i++;
	}
	return (0);
}

/* int main()
{
    char orig[] = "olha que loucura";
    char tofind[] = "ou";
    size_t n = 16;
    printf("%s\n", ft_strnstr(orig, tofind, n));
    printf("%s", strnstr(orig, tofind, n));
} */