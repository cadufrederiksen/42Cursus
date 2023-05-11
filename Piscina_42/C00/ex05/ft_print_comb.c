/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:03:32 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/14 17:18:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_all(int p1, int p2, int p3)
{
	write(1, &p1, 1);
	write(1, &p2, 1);
	write(1, &p3, 1);
	if (p1 != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	p1;
	int	p2;
	int	p3;

	p1 = '0';
	while (p1 <= '7')
	{
		p2 = p1 + 1;
		while (p2 <= '8')
		{
			p3 = p2 + 1;
			while (p3 <= '9')
			{
				ft_print_all(p1, p2, p3);
				p3++;
			}
			p2++;
		}
		p1++;
	}
}
