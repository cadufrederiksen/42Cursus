/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:00 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/20 14:51:51 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb *rotate_a(t_numb *pile_one)//funciona quando chamada varia vezes
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	actual_pile = pile_one->next;	//excluo o primeiro número 
	aux = pile_one;
	aux->next = NULL; //guardo só o primeiro número de pile
	pile_one = actual_pile;//atualizo sem a primeira posição
	while (actual_pile -> next != 0)
		actual_pile = actual_pile->next; //vou ao ultimo nó da lista
	actual_pile->next = aux; //adiciono o que tiver em aux ao final
	free(aux);
	return (pile_one);
}

t_numb *reverse_rotate_a(t_numb *pile_one)//funciona quando chamada varia vezes
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	aux = pile_one; //aux guarda todo o valor de pile A
	actual_pile = aux->next; //AP guarda todo o valor menos a primeira posição
	while(actual_pile->next != NULL)
	{
			aux = aux->next; //termina na penúltima posição
			actual_pile = actual_pile->next; //termina na ultima posição(ou seja a última vira a primeira)
	}
	aux->next = NULL; //elimina a última posição
	actual_pile->next = pile_one; //depois da última posição(agora primeira)adiciona o resto dos números
	pile_one = actual_pile; //igualamos o original a isso
	free(aux);
	return(pile_one);
}

t_state *push_a (t_state *state) //funciona quando chamada variaz vezes mas há alguma problema com free
{
	t_state *actual_state;
	t_numb *aux_push;
	t_numb *aux_pile;
	
	if(!state->pile_one)
		return (state);	
	if(!state->pile_two)
		state->pile_two = allocate_pile();//inicializamos a asegunda pila se não estiver inicializada
	actual_state = state;
	aux_push = allocate_pile();
	aux_pile = allocate_pile();
	aux_push = actual_state->pile_one;//guardamos o primeiro valor da pile A
	actual_state->pile_one = actual_state->pile_one->next; //excluimos esse valor
	aux_push->next = NULL;//aux contém apenas um valor;
 	if(!state->pile_two->content)
		actual_state->pile_two = aux_push; //colocamos esse valor na primeira posição de B se vazio
	else
	{
		aux_pile = state->pile_two; //fazemos um swap para colocar o valor de aux antes dos valores que estejam em pile two
		actual_state->pile_two = aux_push;
		actual_state->pile_two->next = aux_pile;
	}
	return(state);
}

t_numb *swap_a(t_numb *pile_one)
{
	t_numb *aux;
	t_numb *aux2;
	t_numb *actual_pile;

	if(!pile_one || !pile_one->next)
		return(0);
	aux = allocate_pile();
	aux2 = allocate_pile();
	actual_pile = pile_one;
	aux = actual_pile; //salva a primeira posicao
	aux2 = pile_one->next; //salva a segunda
	actual_pile = actual_pile->next->next; //excluimos as duas primeiras
	aux2 ->next = aux; //colocomas a primeeira depois da segunda(swap)
	aux2->next->next = actual_pile;//colocomas depois o restante
	pile_one = aux2;
	return(pile_one);
}
