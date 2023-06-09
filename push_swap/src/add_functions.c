/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:41:03 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/12 16:16:31 by carmarqu         ###   ########.fr       */
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

void	add_index2(t_state *pile_a, char **argv, int argc)
{
	int		x;
	t_state	*tmp;

	x = 0;
	ft_sort_params(argc, argv, x);
	tmp = pile_a;
	while (tmp)
	{
		x = 0;
		while (x < argc)
		{
			if (tmp->value == ft_atoi(argv[x]))
				tmp->index = x + 1;
			x++;
		}
		tmp = tmp->next;
	}
}

void	add_index(t_state *pile_a, char **argv, int argc, int checker)
{
	int		x;
	t_state	*tmp;

	x = 1;
	if (checker == 2)
	{
		add_index2(pile_a, argv, argc);
		return ;
	}
	ft_sort_params(argc, argv, x);
	tmp = pile_a;
	while (tmp)
	{
		x = 1;
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
	t_state	*auxA;
	t_state	*auxB;

	auxB = pileB;
	while (auxB)
	{
		auxA = pileA;
		while (auxA)
		{
			if (auxB->index == (auxA->index - 1))
			{
				auxB->target = auxA->pile_pos;
				break ;
			}
			else if(auxB->index == (auxA->index + 1))
			{
				auxB->target = auxA->pile_pos + 1;
				break ;
			}
			auxB->target = -1;
			auxA = auxA->next;
		}
		auxB = auxB->next;
	}
}
