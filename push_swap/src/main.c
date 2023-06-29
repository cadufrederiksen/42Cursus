/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:35:16 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/29 18:35:42 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_state *pile_a;
	t_state *pile_b;//saber onde incializar
	
	
	int x;
	x = 1;
 	if(check_args(argv) == 0)
	{
		write(1, "Error\n", 6);
		return(0);
	} 
	while(x < argc)
	{
		add_new(&pile_a, create_newA(argv[x]));
		x++;
	}
	add_final_idx(pile_a, argv, argc);
	//pile_b = allocate_state();
	push_pile(&pile_a, &pile_b);
	push_pile(&pile_a, &pile_b);
	push_pile(&pile_a, &pile_b);
	push_pile(&pile_b, &pile_a);
	
	while(pile_a)
	{
		printf("PILA A: %d Index: %d\n", pile_a->value, pile_a->index);
		pile_a = pile_a->next;
	}
	while(pile_b)
	{
		printf("PILA B: %d Index: %d\n", pile_b->value, pile_b->index);
		pile_b = pile_b->next;
	}
	return(0);
}