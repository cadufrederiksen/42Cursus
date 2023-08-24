/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:25:11 by carmarqu          #+#    #+#             */
/*   Updated: 2023/08/24 15:58:37 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size2(t_state **pile)
{
	if ((*pile)->index > (*pile)->next->index)
		do_sa(pile);
}

void	size3(t_state **pile)
{
	while (!check_pile(*pile))
	{
		if ((*pile)->index > (*pile)->next->index
			&& (*pile)->index > (*pile)->next->next->index)
			do_ra(pile);
		else if ((*pile)->index < (*pile)->next->index
				&& (*pile)->next->index > (*pile)->next->next->index)
			do_rra(pile);
		else
			do_sa(pile);
	}
}

void select_alg(int size, t_state **pile_a, t_state **pile_b)//problema com 4 números
{
	if(size == 2)
		size2(pile_a);
	else if(size == 3)
		size3(pile_a);
	else if(size > 3)
		over3_A(pile_a, pile_b, size);
}

void push_swap(int argc, char **argv, int checker)
{
	t_state *pile_b;
	t_state *pile_a;
	int x;
	
	pile_a = NULL;
	pile_b = NULL;
	x = 1;
	if(checker == 2)
		x = 0;
	while(x < argc)
	{
		add_new(&pile_a, create_newA(argv[x]));
		x++;
	}
	x = 1;
	if(checker == 2)
		x = 0;
	add_index(pile_a, argv, argc, checker);
	if(check_pile(pile_a) == 1)
		return ;
	select_alg(argc - x, &pile_a, &pile_b); 
 	while(pile_a)
	{
		printf("PILA A: %d Index: %d \n", pile_a->value, pile_a->index);
		pile_a = pile_a->next;
	}
	 while(pile_b)
	{
		printf("PILA B: %d Index: %d Pile_Pos: %d Target: %d PriceA: %d PriceB: %d Final_Price: %d \n", pile_b->value, pile_b->index, pile_b->pile_pos,
		pile_b->target, pile_b->PriceA, pile_b->PriceB, pile_b->final_price);
		pile_b = pile_b->next;
	}    
	free(pile_a);
	free(pile_b);
}
