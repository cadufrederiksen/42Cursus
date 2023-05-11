/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:14:33 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/13 18:00:17 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	p1;
	int	p2;

	p1 = 0;
	p2 = 1;
	while (p1 <= 98)
	{
		p2 = p1 + 1;
		while (p2 <= 99)
		{
			ft_putchar(p1 / 10 + '0');
			ft_putchar(p1 % 10 + '0');
			write(1, " ", 1);
			ft_putchar(p2 / 10 + '0');
			ft_putchar(p2 % 10 + '0');
			if (p2 != 99 || p1 != 98)
			{
				write(1, ", ", 2);
			}
			p2++;
		}
		p1++;
	}
}
