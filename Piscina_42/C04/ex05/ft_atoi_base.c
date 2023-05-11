/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:35:05 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/30 10:20:38 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_is_neg(char *str)
{
	int	i;
	int	neg;

	neg = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (neg);
}

int	ft_count_and_check(char *base)
{
	int	i;
	int	size;
	int	x;

	i = 0;
	size = 0;
	while (base[size] != '\0')
		size++;
	while (base[i] != '\0')
	{
		x = i + 1;
		if (base[i] == 43 || base[i] == 45)
			return (0);
		while (base[x] != '\0')
		{
			if (base[x] == base[i])
				return (0);
			x++;
		}
		i++;
	}
	return (size);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	unsigned int	nbr;
	unsigned int	base_size;
	unsigned int	x;

	i = 0;
	base_size = ft_count_and_check(base);
	if (base_size <= 1)
		return (0);
	else
	{
		while (str[i] != '\0')
		{
			x = 0;
			while (base[x] != '\0')
			{
				if (str[i] == base[x])
					nbr = nbr * base_size + x;
				x++;
			}
			i++;
		}
	}
	return (nbr * ft_is_neg(str));
}
