/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:00 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/23 16:52:45 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb *rotate_pile(t_numb *pile)//funciona quando chamada varia vezes
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	actual_pile = pile->next;	//excluo o primeiro número 
	aux = pile;
	aux->next = NULL; //guardo só o primeiro número de pile
	pile = actual_pile;//atualizo sem a primeira posição
	while (actual_pile->next != NULL)//aqui me da seg fault!!!!!!!!
		actual_pile = actual_pile->next; //vou ao ultimo nó da lista
	actual_pile->next = aux; //adiciono o que tiver em aux ao final
	free(aux);
	return (pile);
}

t_numb *reverse_rotate_pile(t_numb *pile)//funciona quando chamada varia vezes
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	aux = pile; //aux guarda todo o valor de pile A
	actual_pile = aux->next; //AP guarda todo o valor menos a primeira posição
	while(actual_pile->next != NULL)
	{
		aux = aux->next; //termina na penúltima posição
		actual_pile = actual_pile->next; //termina na ultima posição(ou seja a última vira a primeira)
	}
	aux->next = NULL; //elimina a última posição
	actual_pile->next = pile; //depois da última posição(agora primeira)adiciona o resto dos números
	pile = actual_pile; //igualamos o original a isso
	free(aux);
	return(pile);
}

t_numb *swap_pile(t_numb *pile)
{
	t_numb *aux;
	t_numb *aux2;
	t_numb *actual_pile;

	if(!pile || !pile->next)
		return(0);
	aux = allocate_pile();
	aux2 = allocate_pile();
	actual_pile = pile;
	aux = actual_pile; //salva a primeira posicao
	aux2 = pile->next; //salva a segunda
	actual_pile = actual_pile->next->next; //excluimos as duas primeiras
	aux2 ->next = aux; //colocomas a primeeira depois da segunda(swap)
	aux2->next->next = actual_pile;//colocomas depois o restante
	pile = aux2;
	return(pile);
}

t_state *ss_function(t_state *state)
{
	swap_pile(state->pile_one);
	swap_pile(state->pile_two);
	return(state);
}
