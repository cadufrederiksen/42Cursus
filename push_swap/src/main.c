/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:14:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/15 15:06:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char** argv)
{
	t_state *state;
	int x;
	
	x = 1;
	state = (t_state*)malloc(sizeof(t_state));
	if (argc == 1 || !state)
		return 0;
	while(x < argc)
	{
		state->pile_one = add_number(state->pile_one, argv[x]); //adicionar cada número recibido como argumento na lista
		x++;
	}
	state->pile_one = rotate_a(state->pile_one);
	while(state->pile_one != NULL)
	{
		printf("%d\n", state->pile_one->content);
		state->pile_one = state->pile_one->next;
	}
	state->size = (argc - 1);
	return (0);
}