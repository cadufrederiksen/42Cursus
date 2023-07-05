/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:50:45 by carmarqu          #+#    #+#             */
/*   Updated: 2023/07/05 12:49:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//aqui estão definidas as estruturas mas ainda nao estão inicializadas
typedef	struct s_state
{
	int index; 	//posição final OK!
	int value; 	//número OK!
	int pile_pos;	//posição atual em pile
	int target;		//Posição em A na qual os números que estão em B deveriam "entrar"
	int size;
	int priceA;
	int priceB;
	struct s_state *next;
	
}t_state;

t_state	*create_newA(char *argv);
t_state	*last_list(t_state *lst);
void	add_new(t_state **lst, t_state *new);
int check_args(char **argv);
int main(int argc, char **argv);
char	**ft_sort_params(int argc, char **argv, int j);
void add_index(t_state *pile_a, char **argv, int argc);
void swap_pile(t_state **pile_a);
void rotate_pile(t_state **pile);
t_state *last_list(t_state* lst);
void reverse_rotate_pile(t_state **pile);
t_state *allocate_state();
void push_pile(t_state **a, t_state **b);
void size2(t_state **pile);
void size3(t_state **pile);
int check_pile(t_state *pile);
void add_pile_pos(t_state *pile);
void add_target (t_state *pileA, t_state *pileB);
int check_min_max(char **argv);
int check_all(char **argv);
int check_dup(char **argv);
int calc_size (t_state *pile);
void do_sa(t_state** pile);
void do_ra(t_state **pile);
void do_rra(t_state **pile);
void do_pb(t_state **pile_a, t_state **pile_b);
void do_sb(t_state** pile);
void do_rb(t_state **pile);
void do_rrb(t_state **pile);
void do_pa(t_state **pile_a, t_state **pile_b);
int new_argc(char **argv);
void	over3_A(t_state **pile_a, t_state **pile_b);
void Over3_B(t_state **pile_a, t_state **pile_b, int sizeB);

#endif

 