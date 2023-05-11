/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:35:38 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/30 10:20:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	negative(char *str)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45 || (str[i] >= 48 && str[i] <= 57)
		|| str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	return (n);
}

int	ft_atoi(char *str)
{
	long int	x;
	int			i;

	i = 0;
	x = 0;
	while (str[i] == 43 || str[i] == 45 || (str[i] >= 48 && str[i] <= 57)
		|| str[i] == 32 || (str[i] >= 9 && str[i] <= 13 && str[i] != '\0'))
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			x *= 10;
			x += str[i] - 48;
			i++;
			if (str[i] < 48 || str[i] > 57)
				return (x * negative(str));
		}
		i++;
	}
	return (0);
}
