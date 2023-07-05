/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:12:51 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/05 12:55:19 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sizeA2(t_state **pile)
{
	if ((*pile)->index > (*pile)->next->index)
	{
		swap_pile(pile);
		write(1, "sa\n", 3);
	}
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

void	over3_A(t_state **pile_a, t_state **pile_b)//testando para 5 digitos
{
	int sizeB;
	int sizeA;

	sizeA = calc_size(*pile_a);
	sizeB = 0;
	while (calc_size(*pile_a) != 3 )//enquanto não tem apenas 3 numeros em pila A
	{
		if((*pile_a)->index <= (sizeA / 2)) //se nao for nenhum dos tres ultimos 
		{	
			do_pb(pile_a, pile_b);//envia para B
			sizeB++;
		}
		else
			do_rra(pile_a); // se não roda(melhorar esse algoritmo)
	}
	size3(pile_a);
	Over3_B(pile_a, pile_b, sizeB);
}

void Over3_B(t_state **pile_a, t_state **pile_b, int sizeB)
{
	while(sizeB > 0)
	{
		//add_target(*pile_a, *pile_b);
		//add_pile_pos(*pile_a);
		//add_pile_pos(*pile_b);
		if((*pile_b)->target == 0)
		{
			if((*pile_b)->value > (*pile_b)->next->value)
				do_ra(pile_b);
			do_pa(pile_b, pile_a);
			sizeB--;
		}	
		
	}
}