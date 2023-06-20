/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:14:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/20 16:42:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int n1;
	int n2;

	n1 = ft_atoi(s1);
	n2 = ft_atoi(s2);
	if(n1 > n2)
		return(1);
	if(n2 > n1)
		return(-1);
	return(0);
		
	
}

char	**ft_sort_params(int argc, char **argv)//montar um array que ordene os argv
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
			if (ft_strcmp(argv[j], argv[i]) > 0)
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

t_numb *add_index(t_numb *pile_one, char **argv, int argc)
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

int main(int argc, char** argv)
{
	t_state *state;
	
	int x;

	x = 1;
	state = allocate_state();
	state->pile_one = allocate_pile();
	if (argc <= 1)
		return (0);
	while(x < argc)
	{
		state->pile_one = add_number(state->pile_one, argv[x]); //adicionar cada número recibido como argumento na lista
		x++;
	}
	ft_sort_params(argc, argv); 
	add_index(state->pile_one, argv, argc);
	state->pile_one = rotate_a(state->pile_one);
	state->pile_one = swap_a(state->pile_one);
	
	while(state->pile_one != NULL)
	{
		printf("PILA A: %d Index: %d\n", state->pile_one->content, state->pile_one->index);
		state->pile_one = state->pile_one->next;
	}
 	while(state->pile_two != NULL)
	{
		printf("PILA A: %d Index: %d\n", state->pile_two->content, state->pile_two->index);
		state->pile_two = state->pile_two->next;
	}
	state->size = (argc - 1);
	printf("Size: %d\n", state->size); 
	return (0);
}
