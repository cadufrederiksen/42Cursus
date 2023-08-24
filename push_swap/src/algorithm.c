/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:12:51 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/24 12:26:37 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void final_sort(t_state **pile_a, int size)
{
	int pos;
	int sort;	

	pos = find_idx(*pile_a, 1);//buscamos a posicao do index 1
	if(pos > size / 2)
		sort = pos - size;
	else	
		sort = pos;
	while(sort > 0)//vemos se esta antes ou depois do meio e rodamos
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

int push_under(t_state **pile_a, t_state **pile_b, int size)
{
	int sizeB; //fazer pb dos primeiros menores

	sizeB = 0;
	while (sizeB < size / 2)
	{
		if ((*pile_a)->index <= size / 2)
		{
			do_pb(pile_a, pile_b);
			sizeB++;
		}
		else
			do_ra(pile_a);
	}
	return(sizeB);
}

void	Over3_B(t_state **pile_a, t_state **pile_b, int sizeB, int sizeA)
{
	t_state	*auxB;

	while (sizeB > 0)
	{
		auxB = *pile_b;
		prices(*pile_a, *pile_b, sizeA, sizeB);
		if ((*pile_b)->final_price == 0)
		{
			do_pa(pile_b, pile_a);
			sizeB--;
			sizeA++;
		}
		else
		{
			while (auxB->final_price != find_price(*pile_b))
				auxB = auxB->next;
			Over3_moves(pile_a, pile_b, auxB->PriceA, auxB->PriceB);
		}
	}
	final_sort(pile_a, sizeA);
}

void	over3_A(t_state **pile_a, t_state **pile_b, int size)
{
	int sizeB;
	int sizeA;
	
	
	sizeB = push_under(pile_a, pile_b, size);
	sizeA = size - sizeB;
	while (sizeA != 3)
	{
		if ((*pile_a)->index < size / 2 || (*pile_a)->index <= size - 3)
		{
			do_pb(pile_a, pile_b);
			sizeB++;
			sizeA--;
		}
		else
			do_ra(pile_a);
	}
	size3(pile_a);
	Over3_B(pile_a, pile_b, sizeB, sizeA);
}