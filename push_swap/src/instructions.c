/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:00 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/15 16:48:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_numb	*swap_a(t_numb *pile_one)
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	actual_pile = pile_one; // fazemos uma cópia de pile_one
	aux->content = actual_pile->content;              // guardamos o conteúdo a primeira posição
	actual_pile->content = actual_pile->next->content;//a primeira posição recebe o valor da segunda
	actual_pile->next->content = aux->content;       // a segunda recebe o valor guardado em aux
	free(aux);
	return (pile_one);
}

t_numb *reverse_rotate_a(t_numb *pile_one)//esse é o reverse rotate
{
	t_numb *aux;
	t_numb *actual_pile;

	aux = allocate_pile();
	actual_pile = pile_one; //primeira posição
	aux = pile_one->next; //segunda posição vira a primeira
	while(aux->next != 0)
	{
		actual_pile = actual_pile->next; //termina uma antes do final
		aux = aux->next; //termina ao final
	}
	actual_pile->next = NULL;	//exclui o ultimo numero do final
	aux->next = pile_one; //adiciona depois do ultimo(agora primeiro) o resto dos números
	pile_one = aux;
	free(aux);
	//free(actual_pile); não me deixa librar a memória(seg fault)
	return (pile_one);
}

t_numb *rotate_a(t_numb *pile_one)
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

t_state *push_a (t_state *state)
{
	t_state *actual_state;
	t_state *aux;

	actual_state = state;
	
	aux = allocate_state();
	return(state);

	
}