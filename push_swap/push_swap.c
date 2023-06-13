/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/12 17:13:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_numb *add_number (t_numb *pile_one, char *argv)
{
	t_numb *new_n;
	t_numb *aux;

	new_n = (t_numb *)malloc(sizeof(t_numb));
	if(!new_n)
		return 0;
	new_n->content = ft_atoi(argv); //recebe o número
	new_n->next = NULL; //indica o final
	if(!pile_one)//se é a primeira vez so adiciona o valor
		pile_one = new_n;
	else //se não adicionamos à seguinte lista
	{	
		aux = pile_one;//fazemos uma "cópia" da lista para não modificar la
		while(aux->next != NULL)
			aux = aux->next;//"buscamos" um espaço livre que recebera o novo parametro
		aux -> next = new_n; //recebe o novo número
	}
	return pile_one;
}

int main(int argc, char** argv)
{
	t_state *state;
	t_state *actual_state;
	t_numb *num;
	int x;
	
	x = 1;
	actual_state = (t_state*)malloc(sizeof(state));
	if (argc == 1 || !actual_state)
		return 0;
	if(!state)
		state = actual_state;
	while(x < argc)
	{
		actual_state->pile_one = add_number(actual_state->pile_one, argv[x]); //adicionar cada número recibido como argumento na lista
		x++;
	}
	while(actual_state->pile_one != NULL)
	{
		printf("%d\n", actual_state->pile_one->content);
		actual_state->pile_one = actual_state->pile_one->next;
	}
	return 0;
}