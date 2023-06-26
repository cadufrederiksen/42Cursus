/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:55:10 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/26 14:55:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb	*size2(t_numb *pile_one)
{
	if (pile_one->final_idx > pile_one->next->final_idx)
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
		if (pile_one->final_idx > pile_one->next->final_idx
			&& pile_one->final_idx > pile_one->next->next->final_idx)
		{
			pile_one = rotate_pile(pile_one);
			write(1, "ra\n", 3);
		}
		else if (pile_one->final_idx < pile_one->next->final_idx
				&& pile_one->next->final_idx > pile_one->next->next->final_idx)
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

t_state *over3_A(t_state *state)//testando para 5 digitos
{
	int pushed;
	int last_idx;

	pushed = 0;
	while ((state->size - pushed) != 3 )//enquanto não tem apenas 3 numeros em pila A
	{
		last_idx = last_index(state->pile_one);
		if(state->pile_one->final_idx <= (state->size - 3)) //se nao for nenhum dos tres ultimos 
		{	
			state = push_a(state);//envia para B
			write(1, "pa\n", 3);
			pushed++;
		}
		else
		{
			state->pile_one = rotate_pile(state->pile_one); // se não roda(melhorar esse algoritmo)
			write(1, "ra\n", 4);
		}
	}
	state->pile_one = size3(state->pile_one);//ordena os 3 elementos de pile A(max 2 movimentos)
	state = over3_B(state, pushed);
	return(state);
}

t_state *over3_B(t_state *state, int pushed)
{
	int target;
	int last_idx;
	
	while(pushed != 0)
	{
		target = state->pile_one->final_idx - 1;
		last_idx = last_index(state->pile_two);
		if(state->pile_two->final_idx == target) //se o índice do topo de B for o proximo de A
		{
			state = push_b(state);//envia para A
			write(1, "pb\n", 3);
			pushed--;
		}
		else if(last_idx == target)//(falta colocar alguamas condições aqui)se não for, roda
		{
			state->pile_two = reverse_rotate_pile(state->pile_two);//seg fault
			write(1, "rrb\n", 4);
		}
		else if(state->pile_two->next->final_idx == target)
		{
			state->pile_two = swap_pile(state->pile_two);
			write(1, "sb\n", 3);
		}	
		else 
		{
			state->pile_two = rotate_pile(state->pile_two);
			write(1, "rb\n", 3);	
		}
	}
	return(state);
} 