/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:43:25 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/11 16:12:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nhex(unsigned long long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
		n *= -1;
	if (n > 15)
	{
		while (n != 0)
		{
			size++;
			n /= 16;
		}
	}
	else
		size++;
	return (size);
}

int	ft_printhex(unsigned int n, char type)
{
	char	*base;
	long	nbr;

	nbr = n;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_printhex(nbr / 16, type);
		nbr %= 16;
	}
	write(1, &base[nbr], 1);
	return (count_nhex(n));
}

void	recursive_ptr(unsigned long long nbr, char *base)
{
	if (nbr > 15)
	{
		recursive_ptr(nbr / 16, base);
		nbr %= 16;
	}
	write(1, &base[nbr], 1);
}

int	ft_putptr(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "0x", 2);
	recursive_ptr(n, base);
	return (count_nhex(n) + 2);
}
