/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:12:51 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/14 15:17:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size2(t_state **pile)
{
	if ((*pile)->index > (*pile)->next->index)
		do_sa(pile);
}

void	size3(t_state **pile)
{
	while (!check_pile(*pile))
	{
		if ((*pile)->index > (*pile)->next->index
			&& (*pile)->index > (*pile)->next->next->index)
			do_ra(pile);
		else if ((*pile)->index < (*pile)->next->index
				&& (*pile)->next->index > (*pile)->next->next->index)
			do_rra(pile);
		else
			do_sa(pile);
	}
}

void final_sort(t_state **pile_a)
{
	int pos;
	int sort;	

	pos = find_idx(*pile_a, 1);
	if(pos > calc_size(*pile_a) / 2)
		sort = pos - calc_size(*pile_a);
	else	
		sort = pos;
	while(sort > 0)
	{
		do_ra(pile_a);
		sort--;
	}
	while(sort < 0)
	{
		do_rra(pile_a);
		sort++;
	}
}

void	Over3_B(t_state **pile_a, t_state **pile_b, int sizeB)
{
	t_state	*auxB;

	while (sizeB > 0)
	{
		auxB = *pile_b;
		prices(*pile_a, *pile_b);
		if ((*pile_b)->final_price == 0)// && (*pile_b)->index < (*pile_a)->index)
		{
			do_pa(pile_b, pile_a);
			sizeB--;
		}
		else
		{
			while (auxB->final_price != find_price(*pile_b))
				auxB = auxB->next;
			Over3_moves(pile_a, pile_b, auxB->PriceA, auxB->PriceB);
		}
	}
	final_sort(pile_a);
}
void	over3_A(t_state **pile_a, t_state **pile_b)
{
	int sizeB;
	int sizeA;
	
	sizeA = calc_size(*pile_a);
	sizeB = 0;
	while (calc_size(*pile_a) != 3)
	{
		if ( (*pile_a)->index <= sizeA - 3 || (*pile_a)->index < sizeA / 2 )
		{
			do_pb(pile_a, pile_b);
			sizeB++;
		}
		else
			do_ra(pile_a);
	}
	size3(pile_a);
	Over3_B(pile_a, pile_b, sizeB);
}