/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:05:28 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/07 12:29:22 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void do_sb(t_state** pile)
{
	swap_pile(pile);	
	write(1, "sb\n", 3); 
}

void do_rb(t_state **pile)
{
	rotate_pile(pile);
	write(1, "rb\n", 3);
}

void do_rrb(t_state **pile)
{
	reverse_rotate_pile(pile);
	write(1, "rrb\n", 4);
}

void do_pa(t_state **pile_b, t_state **pile_a)
{
	push_pile(pile_b, pile_a);
	write(1, "pa\n", 3);
}

void do_rrr(t_state **pile_a, t_state **pile_b)
{
	reverse_rotate_pile(pile_a);
	reverse_rotate_pile(pile_b);
	write(1, "rrr\n", 4);
}