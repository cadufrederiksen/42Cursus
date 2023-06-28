/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:44:12 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/27 10:45:44 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if((argv[x][i] < '0' || argv[x][i] > '9') && argv[x][i] != '-')	
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

int check_pile(t_numb *pile)//se estiver ordenado devolve 1 se não 0
{
	t_numb *actual_pile;
	actual_pile = pile;
	while(actual_pile->next != NULL)
	{
		if(actual_pile->final_idx < actual_pile->next->final_idx)
			actual_pile = actual_pile->next;
		else 
			return(0);
	}
	return(1);
}