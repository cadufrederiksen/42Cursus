/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/22 16:48:51 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_numb *add_number (t_numb *pile_one, char *argv)
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	aux->content = ft_atoi(argv); //recebe o número
	if(!pile_one -> content)//se é a primeira vez so adiciona o valor
	{
		pile_one->content = ft_atoi(argv);
	}
	else //se não adicionamos à seguinte lista
	{	
		actual_pile = pile_one;//fazemos uma "cópia" da lista para não modificar la
		while(actual_pile->next != NULL)
			actual_pile = actual_pile->next;//"buscamos" o seguinte espaço livre que recebera o novo parametro
		actual_pile->next = aux; //recebe o novo número
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
	aux->pile_two = NULL;
	return(aux);
}

int check_args(char **argv)
{
	int i;
	int x;
	
	x = 1;
	while(argv[x])
	{
		i = 0;
		while(argv[x][i])
		{
			if(argv[x][i] < '0' || argv[x][i] > '9')	
				return(0);
			else 
				i++;
		}		
		x++;
	}
	x = 1;
	while (argv[x])
	{
		i = x + 1;
		while(argv[i])
		{
			if(ft_atoi(argv[x]) == ft_atoi(argv[i]))
				return(0);
			i++;
		}
		x++;
	}
	return(1);
}