/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:49:26 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/29 15:18:04 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state	*create_newA(char *argv)
{
	t_state	*state;

	state = allocate_state();//aqui pode ser o problema de mem
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

t_state	*last_list(t_state *lst)//devolve um ponteiro para o último nó
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
