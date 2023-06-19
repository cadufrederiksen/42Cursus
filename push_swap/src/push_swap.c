/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/16 16:07:07 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_numb *add_number (t_numb *pile_one, char *argv)
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	aux->content = ft_atoi(argv); //recebe o número
	aux->next = NULL; //indica o final
	if(!pile_one)//se é a primeira vez so adiciona o valor
		pile_one = aux;
	else //se não adicionamos à seguinte lista
	{	
		actual_pile = pile_one;//fazemos uma "cópia" da lista para não modificar la
		while(actual_pile->next != NULL)
			actual_pile = actual_pile->next;//"buscamos" o seguinte espaço livre que recebera o novo parametro
		actual_pile -> next = aux; //recebe o novo número
	}
	return (pile_one);
}

t_numb *allocate_pile()
{
	t_numb *aux;
	
	aux = (t_numb *)malloc(sizeof(t_numb)); //inicializamos aux com memória
	if (!aux)
		return (0);
	aux->next = NULL;
	return(aux);
}

t_state *allocate_state()
{
	t_state *aux;
	
	aux = (t_state *)malloc(sizeof(t_state)); //inicializamos aux com memória
	if (!aux)
		return (0);
	aux->pile_one = NULL;
	return(aux);
}
