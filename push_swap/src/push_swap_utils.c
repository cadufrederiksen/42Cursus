/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/22 17:16:03 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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