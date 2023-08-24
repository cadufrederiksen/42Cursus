/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:52:35 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/24 12:23:55 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_sort_params(int argc, char **argv, int j) //ordena argv
{
	int i;
	char *c;

	while (j < argc)
	{
		i = j + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[j]) > ft_atoi(argv[i]))
			{
				c = argv[i];
				argv[i] = argv[j];
				argv[j] = c;
				i++;
			}
			else
				i++;
		}
		j++;
	}
	return (argv);
}

int	new_argc(char **argv)
{
	int	x;

	x = 0;
	while (argv[x])
		x++;
	return (x);
}

int	calc_size(t_state *pile)
{
	t_state *aux;
	int i;

	i = 0;
	aux = pile;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

int find_idx(t_state *pile, int idx)
{
	t_state *aux;
	
	aux = pile;
	add_pile_pos(pile);
	while(pile)
	{
		if(aux->index == idx)
			return(aux->pile_pos);
		aux = aux->next;	
	}
	return(0);
}

int add_target2(t_state *pile_a, int idx)
{
	t_state *aux;
	int next_big;
	
	next_big = 1000;
	aux = pile_a;
	while (aux)
	{
		if (idx < aux->index) //se o que esta no topo da pila b for menor que o topo da pilaA
		{
			if(next_big > aux->index)//vamos encontra o seguinte numero que seja maior que o topo da pilaB
				next_big = aux->index;// nao o maior de todos da pila a 
		}
		aux = aux->next;
	}
	aux = pile_a;
	while(aux)
	{
		if(aux->index == next_big)//uma vez que descobrimos qual é esse número encontramos a pos dele
 			return(aux->pile_pos);	
		aux = aux->next;
	}
	return(0);	
}

/*
Pila A 		Pila B
4 			1
3
7
9	
queremos encontrar o 3 e não o 9 porque ele é o target do 1
*/