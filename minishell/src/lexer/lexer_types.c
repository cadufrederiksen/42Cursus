/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:13:24 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/17 16:03:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_subtypes(t_lexer *aux, int *file)
{
	if (aux->word[0] == '>' || aux->word[0] == '<')
	{
		*file = 1;
		if (aux->word[0] == '>')
		{
			if (aux->word[1] == '>')
				aux->type = D_GREATER;
			else
				aux->type = GREATER;
		}
		else if (aux->word[0] == '<')
		{
			if (aux->word[1] == '<')
			{
				aux->type = D_LESS;
				aux->next->type = DELIMITER;
				*file = 0;
			}
			else
				aux->type = LESS;
		}
	}
}

void	ft_types_aux(t_lexer *aux, int *flag, int *file)
{
	if (aux->type != DELIMITER)
	{
		if (aux->word[0] == '|')
		{
			*flag = 1;
			aux->type = PIPE;
		}
		else if ((aux->word[0] == '<' || aux->word[0] == '>')
			&& (ft_strlen(aux->word) <= 2))
			ft_subtypes(aux, file);
		else if (*file == 1)
		{
			aux->type = FILE;
			*file = 0;
		}
		else if (*flag == 1)
		{
			aux->type = CMND;
			*flag = 0;
		}
		else if (aux->word[0] == '-')
			aux->type = FLAG;
		else
			aux->type = STRING;
	}
}

void	ft_types(t_lexer **lexer)
{
	t_lexer	*aux;
	int		flag;
	int		file;

	file = 0;
	flag = 1;
	aux = *lexer;
	while (aux)
	{
		ft_types_aux(aux, &flag, &file);
		aux = aux->next;
	}
}
