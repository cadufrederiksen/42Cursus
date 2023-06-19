/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:14:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/19 15:01:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char** argv)
{
	t_state *state;
	int x;

	x = 1;
	state = allocate_state();
	if (argc <= 1)
		return (0);
	while(x < argc)
	{
		state->pile_one = add_number(state->pile_one, argv[x]); //adicionar cada número recibido como argumento na lista
		x++;
	}
	while(state->pile_one != NULL)
	{
		printf("PILA A: %d\n", state->pile_one->content);
		state->pile_one = state->pile_one->next;
	}
	while(state->pile_two != NULL)
	{
		printf("PILA B: %d \n", state->pile_two->content);
		state->pile_two = state->pile_two->next;
	}
	state->size = (argc - 1);
	return (0);
}