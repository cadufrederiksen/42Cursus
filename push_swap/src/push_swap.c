/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/14 10:41:57 by carmarqu         ###   ########.fr       */
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
	int x;
	
	x = 1;
	state = (t_state*)malloc(sizeof(t_state));
	if (argc == 1 || !state)
		return 0;
	while(x < argc)
	{
		state->pile_one = add_number(state->pile_one, argv[x]); //adicionar cada número recibido como argumento na lista
		x++;
	}
	while(state->pile_one != NULL)
	{
		printf("%d\n", state->pile_one->content);
		state->pile_one = state->pile_one->next;
	}
	return 0;
}