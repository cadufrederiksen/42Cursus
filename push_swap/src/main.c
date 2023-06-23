/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:14:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/23 12:46:19 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_pile(t_numb *pile)//se estiver ordenado devolve 1 se não 0
{
	t_numb *actual_pile;
	actual_pile = pile;
	while(actual_pile->next != NULL)
	{
		if(actual_pile->index < actual_pile->next->index)
			actual_pile = actual_pile->next;
		else 
			return(0);
	}
	return(1);
}

char	**ft_sort_params(int argc, char **argv)//ordena argv
{
	int		i;
	int		j;
	char	*c;

	j = 1;
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

int main(int argc, char** argv)
{
	t_state *state;
	int x;

	x = 1;
 	if(check_args(argv) == 0)
	{
		write(1, "Error\n", 6);
		return(0);
	} 
	state = allocate_state();
	state->pile_one = allocate_pile();
	state->size = (argc - 1);
	if (argc <= 1)
		return (0);
	while(x < argc)
	{
		state->pile_one = add_number(state->pile_one, argv[x], x); //adicionar cada número recibido como argumento na lista
		x++;
	}
 	ft_sort_params(argc, argv); 
	add_index(state->pile_one, argv, argc);
	if (!check_pile(state->pile_one))
	{
	if(state->size == 2) 
		state->pile_one = size2(state->pile_one);//funciona perfeitamente
 	else if (state->size == 3)
		state->pile_one = size3(state->pile_one);//funciona perfeitamente
	else	
		state = over3(state, state->size);//funciona perfeitamente com até 5 números
	}
	while(state->pile_one)
	{
		printf("PILA A: %d Index: %d\n", state->pile_one->content, state->pile_one->index);
		state->pile_one = state->pile_one->next;
	}
 	while(state->pile_two != NULL)
	{
		printf("PILA B: %d Index: %d\n", state->pile_two->content, state->pile_two->index);
		state->pile_two = state->pile_two->next;
	} 
	printf("Size: %d\n", state->size); 
	return (0);
}
