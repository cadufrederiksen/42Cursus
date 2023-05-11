/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:34:08 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/30 10:21:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_contar_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_error(char *base)
{
	int	i;
	int	x;

	i = 0;
	if (ft_contar_base(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		x = i + 1;
		while (base[x] != '\0')
		{
			if (base[x] == base[i])
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	basenum;
	unsigned int	error;
	unsigned int	n;

	i = 0;
	basenum = ft_contar_base(base);
	error = ft_error(base);
	if (error == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		n = nbr;
		if (n > basenum)
		{
			ft_putnbr(nbr / basenum, base);
			ft_putchar(base[nbr % basenum]);
		}
		if (n < basenum)
			ft_putchar(base[nbr]);
	}
}
