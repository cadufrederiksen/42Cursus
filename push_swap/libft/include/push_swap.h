/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:50:45 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/14 10:24:20 by carmarqu         ###   ########.fr       */
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
	int content;
	struct s_numb *next;
}t_numb;

//aqui estão definidas as estruturas mas ainda nao estão inicializadas
typedef	struct s_state
{
	t_numb *pile_one;
	t_numb *pile_two;
}t_state;

int main(int argc, char** argv);

#endif

 