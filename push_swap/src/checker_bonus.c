/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:02:39 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/12 15:42:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void check_moves2(t_state **a, t_state **b, char *line)
{
	if(line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		reverse_rotate_pile(a);
	
	if(line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		reverse_rotate_pile(b);
	
	if(line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
	{
		reverse_rotate_pile(b);
		reverse_rotate_pile(a);
	}	
}

void check_moves(t_state **a, t_state **b, char *line)
{
	if(line[0] == 's' && line[1] == 'a')
		swap_pile(a);
	
	if(line[0] == 's' && line[1] == 'b')		
		swap_pile(b);
	
	if(line[0] == 's' && line[1] == 's')
	{
		swap_pile(a);
		swap_pile(b);
	}
	
	if(line[0] == 'r' && line[1] == 'a')
		rotate_pile(a);
	
	if(line[0] == 'r' && line[1] == 'b')
		rotate_pile(b);
	
	if(line[0] == 'r' && line[1] == 'r')
	{
		rotate_pile(b);
		rotate_pile(a);
	}
	
	if(line[0] == 'p' && line[1] == 'a')
		push_pile(b, a);
	
	if(line[0] == 'p' && line[1] == 'b')
		push_pile(a, b);
	else
		check_moves2(a, b, line);
}

void init_checker(char **argv, int checker)
{
	char *line;
	t_state *pile_b;
	t_state *pile_a;
	
	pile_a = NULL;
	pile_b = NULL;
	if(!check_all(argv, checker, &pile_a))
		exit(2);
	line = get_next_line(0);//stdout = 0
	while(line)
	{
		line = get_next_line(0);//stdout = 0
		check_moves(&pile_a, &pile_b, line);
	}
	if(check_pile(pile_a) == 1)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	while(pile_a)
	{
		ft_printf("Value: %d, Index: %d\n", pile_a->value, pile_a->index);
		pile_a = pile_a->next;
	}
	free_pile(&pile_a);
	free_pile(&pile_b);	
	free(line);
}

int main (int argc, char **argv)
{
	int checker;

	checker = argc;	
	if(argc <= 1)	
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1] , ' ');
		argc = new_argc(argv);// aqui recorre todos os números
	}
	push_swap(argc, argv, checker);
	init_checker(argv, checker);
}