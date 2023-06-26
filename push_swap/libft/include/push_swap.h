/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:50:45 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/26 12:31:07 by carmarqu         ###   ########.fr       */
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
	int index; //posição final
	int content; //número
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
t_state *over3_B(t_state *state, int pushed);
t_state *over3_A(t_state *state);
int check_pile(t_numb *pile);
int check_args(char **argv);
t_numb *add_index(t_numb *pile_one, char **argv, int argc);
char	**ft_sort_params(int argc, char **argv);
int last_index(t_numb *pile);

#endif

 