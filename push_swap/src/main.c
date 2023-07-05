/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:35:16 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/05 11:36:48 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_state *pile_a;
	t_state *pile_b;//saber onde incializar
	int x;
	
	pile_a = NULL;
	pile_b = NULL;
	x = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1] , ' ');
		x = 0;
		argc = new_argc(argv);
	}
 	if(!check_all(argv))
	{
		write(1, "Error\n", 6);
		return(0);
	} 
	while(x < argc)
	{
		add_new(&pile_a, create_newA(argv[x]));
		x++;
	}
	add_index(pile_a, argv, argc);
	over3_A(&pile_a, &pile_b);
	while(pile_a)
	{
		printf("PILA A: %d Index: %d Pile_Pos: %d\n", pile_a->value, pile_a->index, pile_a->pile_pos);
		pile_a = pile_a->next;
	}
	while(pile_b)
	{
		printf("PILA B: %d Index: %d Pile_Pos: %d Target: %d\n", pile_b->value, pile_b->index, pile_b->pile_pos, pile_b->target);
		pile_b = pile_b->next;
	}
	return(0);
}
