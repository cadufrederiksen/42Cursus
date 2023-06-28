/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:50:45 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/28 09:32:55 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_numb
{
	int final_idx; //posição final OK!
	int value; //número OK!
	int pile_pos;//posição atual em pile
	int target;//Posição em A na qual os números que estão em B deveriam "entrar"
	
	struct s_numb *next; //posição

	
}t_numb;

//aqui estão definidas as estruturas mas ainda nao estão inicializadas
typedef	struct s_state
{
	t_numb *pile_one; 
	t_numb *pile_two;
	int size;
}t_state;

int main(int argc, char** argv);
t_numb *allocate_pile();
t_state *allocate_state();
t_numb *add_number(t_numb *pile_one, char *argv, int x);
t_numb *swap_pile(t_numb *pile_one);
t_numb *reverse_rotate_pile(t_numb *pile_one);
t_numb *rotate_pile(t_numb *pile_one);
t_state *push_a (t_state *state);
t_state *push_b (t_state *state);
t_state *ss_function(t_state *state);
t_state *rr_function(t_state *state);
t_state *rrr_function(t_state *state);
t_numb *size2(t_numb *pile_one);
t_numb *size3(t_numb *pile_one);
int check_pile(t_numb *pile);
int check_args(char **argv);
t_numb *add_final_idx(t_numb *pile_one, char **argv, int argc);
char	**ft_sort_params(int argc, char **argv);
int last_index(t_numb *pile);
t_numb *add_pile_pos(t_numb *pile);
t_numb *add_target (t_state *state);
t_numb *reverse_rotate_b (t_numb *pile_two);
t_numb *rotate_b (t_numb *pile_two);
t_state *over3_B(t_state *state, int pushed);
t_state *over3_A(t_state *state);

#endif

 