/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:37:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/10 15:39:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void prices(t_state *pile_a, t_state *pile_b)
{
	t_state *auxB;
	t_state *auxA;
	
	add_pile_pos(pile_a);
	add_pile_pos(pile_b);
	add_target(pile_a, pile_b);
	auxB = pile_b;
	auxA = pile_a;
	while(auxB)
	{	
		if(auxB->target < 0 && auxB->next)
		{
			auxB->final_price = -1;
			auxB = auxB ->next;	
		}	
		if (auxB->pile_pos > (calc_size(pile_b)/2))
			auxB->PriceB = (auxB->pile_pos - calc_size(pile_b));
		else
			auxB->PriceB = auxB->pile_pos;
		if(auxB->target > calc_size(pile_a)/2)
			auxB->PriceA = (auxB->target - calc_size(pile_a));
		else 
			auxB->PriceA = auxB->target;
		auxB->final_price = abs(auxB->PriceA) + abs(auxB->PriceB);
		auxB = auxB->next;	
	}
}

int find_price(t_state *pile_b)
{
	t_state *auxB;
	int smaller;
	
	smaller = 100;
	auxB = pile_b;
	while(auxB)
	{
		if(auxB->final_price < smaller && auxB->final_price >= 0)
			smaller = auxB->final_price;
		auxB = auxB->next;
	}
	return(smaller);
}
