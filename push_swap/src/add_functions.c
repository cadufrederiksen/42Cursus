/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:14:56 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/23 11:44:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb *add_number (t_numb *pile_one, char *argv, int x)
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	aux->content = ft_atoi(argv); //recebe o número
	if(x == 1)//se é a primeira vez so adiciona o valor
		pile_one->content = ft_atoi(argv);
	else //se não adicionamos à seguinte lista
	{	
		actual_pile = pile_one;//fazemos uma "cópia" da lista para não modificar la
		while(actual_pile->next != NULL)
			actual_pile = actual_pile->next;//"buscamos" o seguinte espaço livre que recebera o novo parametro
		actual_pile->next = aux; //recebe o novo número
	}
	return (pile_one);
}

t_numb *add_index(t_numb *pile_one, char **argv, int argc)//adiciona index(posição final)
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
			if(actual_pile->content == ft_atoi(argv[x]))
				actual_pile->index = x;
			x++;
		}
		actual_pile = actual_pile->next;
	}	
	return(pile_one);
}