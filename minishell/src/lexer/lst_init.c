/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:35:16 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/12 12:16:12 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_lexer	*last_list(t_lexer *lst)//va hasta el final de la lista
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	add_new(t_lexer **lst, t_lexer *new)//añande un nodo a la lista
{
	t_lexer	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = last_list(*lst);
	aux->next = new;
}

void	ft_refresh_id(t_lexer **lexer)//refresca los id de los nodos
{
	t_lexer	*aux;
	int		lap;

	lap = 0;
	aux = *lexer;
	while (aux)
	{
		aux->id = lap;
		lap++;
		aux = aux->next;
	}
}

void	ft_delete_node(t_lexer **lexer, int x)//borra un nodo
{
	t_lexer	*aux;
	t_lexer	*prev;
	int		i;

	i = 0;
	aux = *lexer;
	prev = NULL;
	while (aux)
	{
		if (x == aux->id)
		{
			if (prev)
			{
				prev->next = aux->next;
				aux = prev->next;
			}
			else
				*lexer = aux->next;
			free(aux->word);
			free(aux);
			return;
		}
		else
		{
			prev = aux;
			aux = aux->next;
			i++;
		}
	}
}

t_lexer *create_new(char *input, int x)
{
	t_lexer *node;

	node = NULL;
	node = malloc(sizeof(t_lexer));
	if (!node)
		return (NULL);
	node->word = ft_strdup(input);
	node->next = NULL;
	node->type = 0;
	node->id = x;
	return (node);
}

void create_nodes(t_lexer **lexer, char **input)//crea todos los nudos
{
	int x;

	x = 0;
	if(*lexer)
		ft_free_lexer_lst(lexer);
	while (input && input[x])
	{
		if (input[x][0] != '\0')
			add_new(lexer, create_new(input[x], x));
		x++;
	}
	//ft_free_2d(input);//Da invalid free en algunos casos "cat <minishell.h|ls" no se por qué
}
