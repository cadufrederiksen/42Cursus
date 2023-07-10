/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:12:51 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/10 16:23:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size2(t_state **pile)
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

void Over3_moves(t_state **pile_a, t_state **pile_b, int PriceA, int PriceB)//entra na funcao mas nao nos whiles
{
	while(PriceA < 0 && PriceB < 0)
	{
		do_rrr(pile_a, pile_b);
		PriceA++;
		PriceB++;
	}
	while(PriceA < 0)
	{
		do_rra(pile_a);
		PriceA++;
	}
	while(PriceB < 0)
	{
		do_rrb(pile_b);
		PriceB++;
	}
	while(PriceA > 0 && PriceB > 0)
	{
		do_rr(pile_a, pile_b);
		PriceA--;
		PriceB--;
	}
	while(PriceA > 0)
	{
		do_ra(pile_a);
		PriceA--;
	}
	while(PriceB > 0)
	{
		do_rb(pile_b);
		PriceB--;
	}
}

void Over3_B(t_state **pile_a, t_state **pile_b, int sizeB)
{
	t_state *auxB;
	
	while(sizeB > 0)
	{
		auxB = *pile_b;
		prices(*pile_a, *pile_b);
		if((*pile_b)->final_price == 0 )//  && (*pile_b)->index == ((*pile_a)->index + 1))
		{
			do_pa(pile_b, pile_a);
			sizeB--;
		}
		else
		{
			prices(*pile_a, *pile_b);
			while(auxB->final_price != find_price(*pile_b))//aqui pode dar problema 
				auxB = auxB->next;		
			Over3_moves(pile_a, pile_b, auxB->PriceA, auxB->PriceB);
		}
	}
	//final_sort()
}
void	over3_A(t_state **pile_a, t_state **pile_b)
{
	int sizeB;
	int sizeA;

	sizeA = calc_size(*pile_a);
	sizeB = 0;
	while (calc_size(*pile_a) != 3)//enquanto não tem apenas 3 numeros em pila A
	{
		if((*pile_a)->index <= sizeA - 3) //se nao for nenhum dos tres ultimos 
		{	
			do_pb(pile_a, pile_b);//envia para B
			sizeB++;
		}
		else if (last_index(*pile_a) <= sizeA - 3)
			do_rra(pile_a); // se não roda(melhorar esse algoritmo)
		else 
			do_ra(pile_a);
	}
	size3(pile_a);
	Over3_B(pile_a, pile_b, sizeB);
}