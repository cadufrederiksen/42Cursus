/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:02:32 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/26 11:35:49 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state	*push_b(t_state *state)
{	
	t_state	*actual_state;
	t_numb	*aux_push;
	t_numb	*aux_pile;
	
	if (!state->pile_two)
		return (state);
	actual_state = state;
	aux_pile = allocate_pile();
	aux_push = allocate_pile();
	aux_push = actual_state->pile_two;
	actual_state->pile_two = actual_state->pile_two->next;
	aux_push->next = NULL;
	aux_pile = state->pile_one;
	actual_state->pile_one = aux_push;
	actual_state->pile_one->next = aux_pile;
	return (actual_state);
}

t_state *push_a (t_state *state) //funciona quando chamada variaz vezes mas há alguma problema com free
{
	t_state *actual_state;
	t_numb *aux_push;
	t_numb *aux_pile;
	if(!state->pile_one)
		return (state);	
	if(!state->pile_two)
		state->pile_two = allocate_pile();//inicializamos a asegunda pila se não estiver inicializada
	actual_state = state;
	aux_push = allocate_pile();
	aux_pile = allocate_pile();
	aux_push = actual_state->pile_one;//guardamos o primeiro valor da pile A
	actual_state->pile_one = actual_state->pile_one->next; //excluimos esse valor
	aux_push->next = NULL;//aux contém apenas um valor;
	aux_pile = state->pile_two; //fazemos um swap para colocar o valor de aux antes dos valores que estejam em pile two
	actual_state->pile_two = aux_push;
	actual_state->pile_two->next = aux_pile;
	return(actual_state);
}

t_state *rr_function(t_state *state)
{
	rotate_pile(state->pile_one);
	rotate_pile(state->pile_two);
	return(state);
}

t_state *rrr_function(t_state *state)
{
	reverse_rotate_pile(state->pile_one);	
	reverse_rotate_pile(state->pile_two);	
	return(state);
}
