/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:12:51 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/22 11:37:49 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int push_under(t_state **pile_a, t_state **pile_b, int sizeA)
{
	int sizeB; //fazer pb dos primeiros menores
	
	while (calc_size(*pile_a) > sizeA / 2 && calc_size(*pile_a) != 3)
	{
		if ((*pile_a)->index <= sizeA / 2)
		{
			do_pb(pile_a, pile_b);
			sizeB++;
		}
		else
			do_ra(pile_a);
	}
	return(sizeB);
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
	sizeB = push_under(pile_a, pile_b, sizeA);
	while (calc_size(*pile_a) != 3)
	{
		if ((*pile_a)->index < sizeA / 2 || (*pile_a)->index <= sizeA - 3)
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