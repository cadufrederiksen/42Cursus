/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:37:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/24 12:54:45 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prices(t_state *pile_a, t_state *pile_b, int sizeA, int sizeB) //adicionar aqui uma maneira de devolver o menor preco
{
	t_state	*auxB;

	add_pile_pos(pile_a);
	add_pile_pos(pile_b);//isso  pode estar demorando muito
	add_target(pile_a, pile_b);
	auxB = pile_b;
	while (auxB)
	{
		if (auxB->pile_pos > (sizeB / 2))
			auxB->PriceB = (auxB->pile_pos - sizeB);
		else
			auxB->PriceB = auxB->pile_pos;
		if (auxB->target > (sizeA / 2))
			auxB->PriceA = (auxB->target - sizeA);
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
