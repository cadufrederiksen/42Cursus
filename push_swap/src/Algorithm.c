/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:55:10 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/21 16:00:07 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb	*size2(t_numb *pile_one)
{
	if (pile_one->index > pile_one->next->index)
	{
		pile_one = swap_a(pile_one);
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
			pile_one = rotate_a(pile_one);
			write(1, "ra\n", 3);
		}
		else if (pile_one->index < pile_one->next->index
				&& pile_one->next->index > pile_one->next->next->index)
		{
			pile_one = reverse_rotate_a(pile_one);
			write(1, "rra\n", 4);
		}
		else
		{
			pile_one = swap_a(pile_one);	
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
	while ((size - pushed) != 3 )
	{
		if(state->pile_one->index <= size - 3)
		{	
			state = push_a(state);
			write(1, "pa\n", 3);
			pushed++;
		}
		else 
		{
			state->pile_one = rotate_a(state->pile_one);
			write(1, "ra\n", 3);
		}
	}
	state->pile_one = size3(state->pile_one);
	while(state->pile_two != NULL)
	{
		indexA = state->pile_one->index;
		if(state->pile_two->index == (indexA - 1))
		{
			state = push_b(state);
			write(1, "pb\n", 3);
		}
		else
			break;
			
	}
	return(state);
}
