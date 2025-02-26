/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cupidash_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:20:41 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/26 18:30:19 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

long int	ft_atoi(const char *str)
{
	long int	x;
	int			i;
	long int	neg;

	neg = 1;
	i = 0;
	x = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return (neg * x);
}

int	check_param(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] > '9' || str[x] < '0')
			return (0);
		x++;
	}
	return (1);
}

void	printmsg(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	free2d(char **map, int nbr)
{
	int	x;

	x = 3 * nbr - 1;
	while (x >= 0)
		free(map[x--]);
	free(map);
}
