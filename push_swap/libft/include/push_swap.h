/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:50:45 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/15 13:36:09 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_numb
{
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
t_numb *swap_a(t_numb *pile_one);
t_numb *allocate_pile();
t_state *allocate_state();
t_numb *add_number(t_numb *pile_one, char *argv);
t_numb *reverse_rotate_a(t_numb *pile_one);
t_numb *rotate_a(t_numb *pile_one);

#endif

 