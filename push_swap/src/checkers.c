/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:23:09 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/12 13:26:43 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *argv)
{
	int i;
	
	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '-')
				return (0);
			else
				i++;
	}
	return(1);
}

int	check_args(char **argv, int x, t_state **pile_a)
{
	int	i;
	

	while (argv[x])
	{
		i = x + 1;	
		if (!check_num(argv[x]) || ft_atoi(argv[x]) < INT_MIN || ft_atoi(argv[x]) > INT_MAX)//passo daqui pode adc
				return(0); 
		while (argv[i])
		{
			if (ft_atoi(argv[x]) == ft_atoi(argv[i])) // OK
				return(0);
			i++;
		}
		add_new(pile_a, create_newA(argv[x]));
		x++;
	}
	return (1);
}

int	check_pile(t_state *pile) //se estiver ordenado devolve 1 se não 0
{
	t_state *aux;
	
	aux = pile;
	while (aux->next != NULL)
	{
		if (aux->index < aux->next->index)
			aux = aux->next;
		else
			return (0);
	}
	return (1);
}

int	check_all(char **argv, int checker, t_state **pile_a)
{
	int x; 

	x = 1;
	if(checker == 2)
		x = 0;
	if (!check_args(argv, x, pile_a))
		return (0);
	else
		return (1);
}