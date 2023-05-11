/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:31:27 by carmarqu          #+#    #+#             */
/*   Updated: 2023/03/17 11:59:12 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	pos;
	int	tmp;

	pos = 0;
	while (pos < size / 2)
	{
		tmp = tab[pos];
		tab[pos] = tab[size - pos - 1];
		tab[size - pos - 1] = tmp;
		pos++;
	}
}
