/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:46:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/28 09:13:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb *allocate_pile()
{
	t_numb *aux;
	
	aux = (t_numb *)malloc(sizeof(t_numb)); //inicializamos aux com memória
	if (!aux)
		return (0);
	aux->next = NULL;
	return(aux);
}

t_state *allocate_state()
{
	t_state *aux;
	
	aux = (t_state *)malloc(sizeof(t_state)); //inicializamos aux com memória
	if (!aux)
		return (0);
	aux->pile_one = NULL;
	return(aux);
}

t_content *allocate_info()
{
	t_content *info;
	
	info = (t_content *)malloc(sizeof(t_content));
	if(!info)
		return(0);
	info = NULL;
	return(info);
}