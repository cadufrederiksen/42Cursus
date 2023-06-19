/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:18:11 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/19 12:56:26 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb *swap_b(t_numb *pile_two)
{
	t_numb *aux;
	t_numb *actual_pile;

	if(!pile_two || !pile_two->next)
		return(0);
	aux = allocate_pile();
	actual_pile = pile_two;
	aux->content = actual_pile->content;
	actual_pile->content = actual_pile->next->content;
	actual_pile->next->content = aux->content;
	free(aux);
	return(pile_two);
}

t_numb *rotate_b (t_numb *pile_two)
{
	t_numb *aux;
	t_numb *actual_pile;
	
	aux = allocate_pile();
	actual_pile = pile_two->next;
	aux = pile_two;
	aux->next = NULL;
	pile_two = actual_pile;
	while(actual_pile->next != NULL)
		actual_pile = actual_pile->next;
	actual_pile->next = aux;
	free(aux);
	return(pile_two);
}

t_numb *reverse_rotate_b (t_numb *pile_two)
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	aux = pile_two;
	actual_pile = aux ->next;
	while(actual_pile ->next != NULL)
	{
		aux = aux->next;
		actual_pile = actual_pile->next;
	}
	aux->next = NULL;
	actual_pile->next = pile_two;
	pile_two = actual_pile;
	free(aux);
	return(pile_two);
}

t_state *push_b (t_state *state)
{
	t_state *actual_state;
	t_numb *aux_push;
	t_numb *aux_pile;

	if(!state->pile_one)
		state->pile_one = allocate_pile();
	actual_state = state;
	aux_pile = allocate_pile();
	aux_push = allocate_pile();
	aux_push = actual_state->pile_two;
	actual_state->pile_two = actual_state->pile_two->next;
	aux_push ->next = NULL;
	if(!state->pile_one->content)
		actual_state->pile_one = aux_push;
	else
	{
		aux_pile = state->pile_one;
		actual_state->pile_one = aux_push;
		actual_state->pile_one->next = aux_pile;
	}
	return(state);	
}