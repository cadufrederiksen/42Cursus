/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:55:10 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/22 17:06:17 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb	*size2(t_numb *pile_one)
{
	if (pile_one->index > pile_one->next->index)
	{
		pile_one = swap_pile(pile_one);
		write(1, "sa\n", 3);
	}
	return (pile_one);
}

t_numb	*size3(t_numb *pile_one)
{
	while (!check_pile(pile_one))
	{
		if (pile_one->index > pile_one->next->index
			&& pile_one->index > pile_one->next->next->index)
		{
			pile_one = rotate_pile(pile_one);
			write(1, "ra\n", 3);
		}
		else if (pile_one->index < pile_one->next->index
				&& pile_one->next->index > pile_one->next->next->index)
		{
			pile_one = reverse_rotate_pile(pile_one);
			write(1, "rra\n", 4);
		}
		else
		{
			pile_one = swap_pile(pile_one);	
			write(1, "sa\n", 3);
		}
	}
	return (pile_one);
} 

t_state *over3(t_state *state, int size)//testando para 5 digitos
{
	int pushed;
	int indexA;

	pushed = 0;
	while ((size - pushed) != 3 )//enquanto não tem apenas 3 numeros em pila A
	{
		if(state->pile_one->index <= size - 3) //se nao for nenhum dos tres ultimos 
		{	
			state = push_a(state);//envia para B
			write(1, "pa\n", 3);
			pushed++;
		}
		else 
		{
			state->pile_one = rotate_pile(state->pile_one); // se não roda(melhorar esse algoritmo)
			write(1, "ra\n", 3);
		}
	}
	state->pile_one = size3(state->pile_one);//ordena os 3 elementos de pile A(max 2 movimentos)
	while(state->pile_two != NULL)
	{
		indexA = state->pile_one->index;
		if(state->pile_two->index == (indexA - 1)) //se o índice do topo de B for o proximo de A
		{
			state = push_b(state);//envia para A
			write(1, "pb\n", 3);
		}
		else if (state->pile_two->index < state->pile_two->next->index)//se não for, roda
		{
			state->pile_two = rotate_pile(state->pile_two);
			write(1, "rb\n", 3);
		}	
	}
	return(state);
}
