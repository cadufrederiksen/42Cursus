/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:43:41 by carmarqu          #+#    #+#             */
/*   Updated: 2023/05/11 13:54:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_n(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	if (n > 9)
	{
		while (n != 0)
		{
			size++;
			n /= 10;
		}
	}
	else
		size++;
	return (size);
}

int	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
	}
	nbr += 48;
	write(1, &nbr, 1);
	return (count_n(n));
}

int	ft_putunbr(unsigned int n)
{
	long	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
	}
	nbr += 48;
	write(1, &nbr, 1);
	return (count_n(n));
}

/* int main()
{
	//ft_putnbr(444);
	printf("%i\n", ft_putnbr(-444));
	return (0);
} */