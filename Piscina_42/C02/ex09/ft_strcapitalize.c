/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:17:16 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/23 10:15:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*to_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	to_lowercase(str);
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && j == 1)
		{
			str[i] = str[i] - 32;
			j = 0;
		}
		if ((str[i] >= '0' && str[i] <= '9') || ((str[i] >= 'a'
					&& str[i] <= 'z')) || (str[i] >= 'A' && str[i] <= 'Z'))
			j = 0;
		else
			j = 1;
		i++;
	}
	return (str);
}
