/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:41:03 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/05 11:29:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_new(t_state **lst, t_state *new)
{
	t_state	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = last_list(*lst);
	aux->next = new;
}

void	add_index(t_state *pile_a, char **argv, int argc)
{
	int		x;
	int	check;
	t_state	*tmp;

	if(argv[0] == NULL)
		check = 1;
	else
		check = 0;
	ft_sort_params(argc, argv, check);
	x = check;
	tmp = pile_a;
	while (tmp)
	{
		x = check;
		while (x < argc)
		{
			if (tmp->value == ft_atoi(argv[x]))
				tmp->index = x;
			x++;
		}
		tmp = tmp->next;
	}
}

void	add_pile_pos(t_state *pile)
{
	t_state	*aux;
	int		pos;

	aux = pile;
	pos = 0;
	while (aux)
	{
		aux->pile_pos = pos;
		aux = aux->next;
		pos++;
	}
}

void	add_target(t_state *pileA, t_state *pileB)
{
	t_state *auxA;
	t_state *auxB;

	auxB = pileB;
	while (auxB)
	{
		auxA = pileA;
		while (auxA)
		{
			if (auxB->index == (auxA->index - 1))
				auxB->target = auxA->pile_pos;
			auxA = auxA->next;
		}
		auxB = auxB->next;
	}
}

int calc_size(t_state *pile)
{
	t_state *aux;
	int i; 
	
	i = 0;
	aux = pile;
	while(aux)
	{ 
		aux = aux->next;
		i++;
	}	
	return(i);
}