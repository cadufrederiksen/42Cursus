/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:47:48 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/29 18:42:02 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_pile(t_state** pile)
{
	t_state *aux;
	
	if(!(*pile) || !(*pile)->next)
		return ;
	aux = *pile; //ponteiro para o inicio da lista
	*pile = (*pile)->next; //aponta para o 2º nó("exclui o 1º")
	aux->next = (*pile)->next; //aponta para o 3º de pile (pile->next->next) ou seja "exclui" o 2º
	(*pile)->next = aux; //agora o 2º passa a ser o primeiro e aponta para aux, que tem o 1º seguido pelos outros

}

void rotate_pile(t_state **pile)
{
	t_state *aux;
	t_state *last;
	
	if(!(*pile) || !(*pile)->next)
		return ;
	aux = *pile;//ponteiro para o ínicio da lista
	*pile = (*pile)->next;//ponteiro para o 2º "exclui" o 1º
	last = last_list(*pile);//ponteiro para o último nó da lista
	aux->next = NULL; //isola o 1º da lista
	last ->next = aux; //o último ponteiro da lista aponta para o primeiro isolado
}

void reverse_rotate_pile(t_state **pile)
{
	t_state *aux;
	t_state *last;

	if(!(*pile) || !(*pile)->next)
		return ;
	aux = *pile; //aux guarda todo o valor de pile A
	last = (*pile)->next; //AP guarda todo o valor menos a primeira posição
	while(last->next != NULL)
	{
		aux = aux->next; //termina na penúltima posição
		last = last->next; //termina na ultima posição(ou seja a última vira a primeira)
	}
	aux->next = NULL;//"exclui" o último
	last->next = *pile; //adiciona depois do último os outros números
	*pile = last; //aponta para last
}

void push_pile(t_state **src, t_state **dest)
{
	t_state *aux;

	aux = *src;
	*src = (*src)->next;
	aux ->next = *dest;
	*dest = aux;
}