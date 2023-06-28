/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:14:56 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/28 09:36:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb *add_number (t_numb *pile_one, char *argv, int x)
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	aux->value = ft_atoi(argv); //recebe o número
	if(x == 1)//se é a primeira vez so adiciona o valor
		pile_one->value = ft_atoi(argv);
	else //se não adicionamos à seguinte lista
	{	
		actual_pile = pile_one;//fazemos uma "cópia" da lista para não modificar la
		while(actual_pile->next != NULL)
			actual_pile = actual_pile->next;//"buscamos" o seguinte espaço livre que recebera o novo parametro
		actual_pile->next = aux; //recebe o novo número
	}
	return (pile_one);
}

t_numb *add_final_idx(t_numb *pile_one, char **argv, int argc)//adiciona index(posição final)
{
	int x;
	t_numb *actual_pile;
	
	actual_pile = pile_one;
	x = 1;
	while(actual_pile != NULL)
	{
		x = 1;
		while(x < argc)
		{
			if(actual_pile->value == ft_atoi(argv[x]))
				actual_pile->final_idx = x;
			x++;
		}
		actual_pile = actual_pile->next;
	}	
	return(pile_one);
}
/* 
t_numb	*add_pile_pos(t_numb *pile)
{
	int pos;

	pos = 0;
	while (pile)
	{
		pile->pile_pos = pos;
		pile = pile->next;
		pos++;
	}
	return (pile);
}
 */
/* t_numb *add_target (t_state *state)
{
	t_numb *pileB;
	t_numb *pileA;

	pileB = state->pile_two;
	while(pileB)
	{
		pileA = state->pile_one;
		while(pileA)
		{
			if (pileB->final_idx == (pileA->final_idx - 1))
				pileB->target = pileA->pile_pos;
			pileA = pileA->next;
		}
		pileB = pileB->next;
	}
	return(pileB);
} */