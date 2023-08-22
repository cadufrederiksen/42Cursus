/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:03:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/22 11:39:00 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Over3_moves(t_state **pile_a, t_state **pile_b, int PriceA, int PriceB)
{
	while (PriceA < 0 && PriceB < 0)
	{
		do_rrr(pile_a, pile_b);
		PriceA++;
		PriceB++;
	}
	while (PriceA < 0)
	{
		do_rra(pile_a);
		PriceA++;
	}
	while (PriceB < 0)
	{
		do_rrb(pile_b);
		PriceB++;
	}
	if (PriceA > 0 || PriceB > 0)
		Over3_moves2(pile_a, pile_b, PriceA, PriceB);
}

void	Over3_moves2(t_state **pile_a, t_state **pile_b, int PriceA, int PriceB)
{
	while (PriceA > 0 && PriceB > 0)
	{
		do_rr(pile_a, pile_b);
		PriceA--;
		PriceB--;
	}
	while (PriceA > 0)
	{
		do_ra(pile_a);
		PriceA--;
	}
	while (PriceB > 0)
	{
		do_rb(pile_b);
		PriceB--;
	}
}