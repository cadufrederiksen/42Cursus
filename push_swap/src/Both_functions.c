/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Both_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/19 14:20:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state *ss_function(t_state *state)
{
	swap_a(state->pile_one);
	swap_b(state->pile_two);
	return(state);
}

t_state *rr_function(t_state *state)
{
	rotate_a(state->pile_one);
	rotate_b(state->pile_two);
	return(state);
}

t_state *rrr_function(t_state *state)
{
	reverse_rotate_a(state->pile_one);	
	reverse_rotate_b(state->pile_two);	
	return(state);
}
