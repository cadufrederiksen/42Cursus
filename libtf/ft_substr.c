/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:43:59 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/01 16:38:17 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			x;
	char			*sub;

	x = 0;
	i = start;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL || s == NULL)
		return (0);
	while (x < len)
	{
		sub[x] = s[i];
		i++;
		x++;
	}
	sub[x] = '\0';
	return (sub);
	free(sub);
}

/* int	main(void)
{
	printf("%s", ft_substr("hola que tal", 4, 5));
}
 */