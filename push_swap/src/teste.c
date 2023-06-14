/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:42:28 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/12 14:42:29 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct nodo
{
	char* num;
	struct nodo *sig;
}Grupo;

Grupo *listaGrupo(Grupo *Lista)
{
	Lista = NULL;
	return Lista;
}

Grupo *agregarGrupo(Grupo *Lista, char* num)
{
	Grupo *nuevoGrupo;
	Grupo *aux;
	nuevoGrupo = malloc(sizeof(Grupo));
	nuevoGrupo->num = num;
	nuevoGrupo->sig = NULL;
	if(!Lista)
	{
		Lista = nuevoGrupo;
	} else {
		aux = Lista;
		while(aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevoGrupo;
	}
	return Lista;
}


int main(int argc, char **argv)
{
	int x;

	x = 1;
	Grupo *Lista = listaGrupo(Lista); 
	while(argv[x] != (void *)0)
	{
		Lista = agregarGrupo(Lista, &argv[x][0]);
		x++;
	}
	while(Lista != NULL)
	{
		printf("%s\n", Lista->num);
		Lista = Lista->sig;
	}
	return 0;	
}