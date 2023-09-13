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
	if(line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_pile(b, a);
	else if(line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_pile(a, b);
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		reverse_rotate_pile(a);
	
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		reverse_rotate_pile(b);
	
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
	{
		reverse_rotate_pile(b);
		reverse_rotate_pile(a);
	}	
}

char *check_moves(t_state **a, t_state **b, char *line)
{
	if(line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_pile(a);
	else if(line[0] == 's' && line[1] == 'b' && line[2] == '\n')		
		swap_pile(b);
	else if(line[0] == 's' && line[1] == 's' && line[2] == '\n')
	{
		swap_pile(a);
		swap_pile(b);
	}
	else if(line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_pile(a);
	else if(line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_pile(b);
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
	{
		rotate_pile(b);
		rotate_pile(a);
	}
	else
		check_moves2(a, b, line);
	return(get_next_line(0));
}

void init_checker(t_state **a, t_state **b)
{
	char *tmp;
	char *line;

	line = get_next_line(0);//stdout = 0
	while(line && *line != '\n')
	{
		tmp = line;
		line = check_moves(a, b, line); 
		free(tmp);
	}
	if(!check_pile(*a) || *b)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	free(line);
}

int main (int argc, char **argv)
{
	int checker;
	t_state *pile_b;
	t_state *pile_a;
	
	pile_a = NULL;
	pile_b = NULL;
	checker = argc;	
	if(argc <= 1)	
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1] , ' ');
		argc = new_argc(argv);// aqui recorre todos os números
	}
	if(!check_all(argv, checker, &pile_a))
		exit(2);
	init_checker(&pile_a, &pile_b);
	free_pile(&pile_a);
	free_pile(&pile_b);	
}