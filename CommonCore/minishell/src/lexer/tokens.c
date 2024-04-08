/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:14:54 by isporras          #+#    #+#             */
/*   Updated: 2024/03/04 15:52:07 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_case_single_double(t_token *t)
{
	char	**tmp;

	t->d = 0;
	if ((t->lx[t->i][t->j] == '>' && t->lx[t->i][t->j + 1] == '>')
		|| (t->lx[t->i][t->j] == '<' && t->lx[t->i][t->j + 1] == '<')
		|| (t->lx[t->i][t->j] == '|' && t->lx[t->i][t->j + 1] == '|'))
	{
		t->d = 2;
		t->tk = ft_substr(t->lx[t->i], t->j, 2);
		tmp = ft_add_token(t);
		(t->j)++;
	}
	else
	{
		t->d = 1;
		t->tk = ft_substr(t->lx[t->i], t->j, 1);
		tmp = ft_add_token(t);
	}
	free(t->tk);
	ft_free_2d(t->lx);
	return (tmp);
}

int	is_token(char c)
{
	return (c == '>' || c == '<' || c == '|');
}

int	is_double_token(t_token *t)
{
	return ((ft_strncmp(&t->lx[t->i][t->j], "<<", 2) == 0)
			|| (ft_strncmp(&t->lx[t->i][t->j], ">>", 2) == 0)
			|| (ft_strncmp(&t->lx[t->i][t->j], "||", 2) == 0));
}

int	is_not_alone(t_token *t)
{
	return ((ft_strncmp(t->lx[t->i], "<<", 3) != 0)
		&& (ft_strncmp(t->lx[t->i], ">>", 3) != 0)
		&& (ft_strncmp(t->lx[t->i], "||", 3) != 0));
}

char	**ft_get_tokens(char **lexer)
{
	t_token	t;

	t.tk = NULL;
	t.lx = lexer;
	t.i = 0;
	while (t.lx[t.i])
	{
		t.j = 0;
		while (t.lx[t.i][t.j])
		{
			if (is_token(t.lx[t.i][t.j]) && (ft_strlen(t.lx[t.i]) != 2)
				&& (ft_between_quotes(t.lx[t.i], t.j) == 0)
				&& is_double_token(&t))
				t.lx = ft_case_single_double(&t);
			else if (is_token(t.lx[t.i][t.j]) && (ft_strlen(t.lx[t.i]) != 1) &&
					(ft_between_quotes(t.lx[t.i], t.j) == 0)
					&& !is_double_token(&t) && is_not_alone(&t))
				t.lx = ft_case_single_double(&t);
			if (t.lx[t.i][t.j])
				(t.j)++;
		}
		if (t.lx[t.i])
			(t.i)++;
	}
	return (t.lx);
}
