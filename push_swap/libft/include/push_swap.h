/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:50:45 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/29 18:16:58 by carmarqu         ###   ########.fr       */
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
	void *next;
	
}t_state;

t_state	*create_newA(char *argv);
t_state	*last_list(t_state *lst);
void	add_new(t_state **lst, t_state *new);
int check_args(char **argv);
int main(int argc, char **argv);
char	**ft_sort_params(int argc, char **argv);
void add_final_idx(t_state *pile_a, char **argv, int argc);
void swap_pile(t_state **pile_a);
void rotate_pile(t_state **pile);
t_state *last_list(t_state* lst);
void reverse_rotate_pile(t_state **pile);
t_state *allocate_state();
void push_pile(t_state **a, t_state **b);

#endif

 