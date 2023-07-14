/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:37:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/14 13:55:51 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prices(t_state *pile_a, t_state *pile_b)//adicionar que e for o número for o menor da pila_a posso fazer pa
{
	t_state	*auxB;
	int flag;
	
	flag = 0;
	add_pile_pos(pile_a);
	add_pile_pos(pile_b);
	add_target(pile_a, pile_b);
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
