/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:06:46 by carmarqu          #+#    #+#             */
/*   Updated: 2023/04/27 12:12:09 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1);
	ptr = (char *)malloc((i + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, i);
	ptr[i] = '\0';
	return (ptr);
	free(ptr);
}

/* int main()
{
	printf("%s", ft_strdup("hola"));
	return(0);
}  */