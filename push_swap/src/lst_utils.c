/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:49:26 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/12 10:36:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state	*create_newA(char *argv)
{
	t_state	*state;

	state = allocate_state();
	state->value = ft_atoi(argv);
	state->next = NULL;
	return (state);
}

t_state	*allocate_state(void)
{
	t_state	*state;

	state = NULL;
	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	return (state);
}

t_state	*last_list(t_state *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

int	last_index(t_state *pile)
{
	t_state *aux;

	aux = pile;
	while (aux->next != 0)
		aux = aux->next;
	return (aux->index);
}