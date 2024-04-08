/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:41:03 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/28 17:41:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int add_target2(t_state *pile_a, int idx)
{
	t_state *aux;
	int next_big;
	int pos;
	
	pos = 0;
	next_big = 1000;
	aux = pile_a;
	while (aux)
	{
		if (idx < aux->index) //se o que esta no topo da pila b for menor que o topo da pilaA
		{
			if(next_big > aux->index)//vamos encontra o seguinte numero que seja maior que o topo da pilaB
			{
				next_big = aux->index;// nao o maior de todos da pila a 
				pos = aux->pile_pos;
			}	
		}
		aux = aux->next;
	}
	return(pos);	
}

/*
Pila A 		Pila B
4 			1
3
7
9	
queremos encontrar o 3 e não o 9 porque ele é o target do 1
*/

void	add_target(t_state *pile_a, t_state *pile_b) //talvez seja possivel otimizar aqui
{
	t_state	*auxA;
	t_state	*auxB;

	auxB = pile_b;
	while (auxB)
	{
		auxA = pile_a;
		while (auxA)
		{
			if (auxB->index == (auxA->index - 1))
				auxB->target = auxA->pile_pos;
			else if(auxB->index == (auxA->index + 1))
				auxB->target = auxA->pile_pos + 1;
			else
				auxB->target = add_target2(pile_a, auxB->index);
			auxA = auxA->next;
		}
		auxB = auxB->next;     
	}
}
