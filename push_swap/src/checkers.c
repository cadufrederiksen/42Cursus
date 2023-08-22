/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:38:07 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/22 11:04:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	int	i;
	int	x;

	x = 1;
	while (argv[x])
	{
		i = 0;
		while (argv[x][i])
		{
			if ((argv[x][i] < '0' || argv[x][i] > '9') && argv[x][i] != '-')
				return (0);
			else
				i++;
		}
		x++;
	}
	return (1);
}

int	check_dup(char **argv)
{
	int	x;
	int	i;

	x = 1;
	while (argv[x])
	{
		i = x + 1;
		while (argv[i])
		{
			if (ft_atoi(argv[x]) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
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

int	check_min_max(char **argv)
{
	int	x;

	x = 1;
	while (argv[x])
	{
		if (ft_atoi(argv[x]) < INT_MIN || ft_atoi(argv[x]) > INT_MAX)
			return (0);
		x++;
	}
	return (1);
}

int	check_all(char **argv)
{
	if (!check_args(argv))
		return (0);
	else if (!check_dup(argv))
		return (0);
	else if (!check_min_max(argv))
		return (0);
	else
		return (1);
}