/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:05 by isporras          #+#    #+#             */
/*   Updated: 2024/02/13 16:55:05 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_delete_pipe(t_lexer **lexer, int pipe)
{
	t_lexer	*aux;
	int		lap;
	int		i;

	lap = 0;
	aux = *lexer;
	i = 0;
	printf("listaaa");
	ft_print_list(lexer);
	while (aux)
	{
		if (aux->type == PIPE)
			lap++;
		if (lap == pipe)
		{
			printf("lexer[%i] %s\n",i, aux->word);
			ft_delete_node(lexer, i);
		}
		aux = aux->next;
		i++;
	}
}
