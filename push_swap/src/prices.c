/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:37:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/12 16:59:16 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int high_idx(t_state *pile_a)
{
	t_state *auxA = pile_a;
	int higher;

	higher = 0;
	while (auxA)
	{
		if (auxA->index > higher)
			higher = auxA->index;
		auxA = auxA->next;
	}
	auxA = pile_a;
	while(auxA->index != higher)
		auxA = auxA->next;
	return (auxA -> pile_pos);
}

void	add_target2(t_state *pile_a, t_state *pile_b)
{
	t_state *auxB;
	int higher;


	higher = high_idx(pile_a);
	auxB = pile_b;
	if(auxB->target == -1)
		auxB->target = higher;
}

void	prices(t_state *pile_a, t_state *pile_b)
{
	t_state	*auxB;

	add_pile_pos(pile_a);
	add_pile_pos(pile_b);
	add_target(pile_a, pile_b);
	//add_target2(pile_a, pile_b);
	auxB = pile_b;
	while (auxB)
	{
		if (auxB->pile_pos > (calc_size(pile_b) / 2))
			auxB->PriceB = (auxB->pile_pos - calc_size(pile_b));
		else
			auxB->PriceB = auxB->pile_pos;
		if (auxB->target > calc_size(pile_a) / 2)
			auxB->PriceA = (auxB->target - calc_size(pile_a));
		else
			auxB->PriceA = auxB->target;
		auxB->final_price = abs(auxB->PriceA) + abs(auxB->PriceB);
		if (auxB->target < 0)
			auxB->final_price = -1;
		auxB = auxB->next;
	}
}

int	find_price(t_state *pile_b)
{
	t_state	*auxB;
	int		smaller;

	smaller = 100;
	auxB = pile_b;
	while (auxB)
	{
		if (auxB->final_price < smaller && auxB->final_price >= 0)
			smaller = auxB->final_price;
		auxB = auxB->next;
	}
	return (smaller);
}
