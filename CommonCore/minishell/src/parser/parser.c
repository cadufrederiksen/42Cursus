/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:52:20 by isporras          #+#    #+#             */
/*   Updated: 2024/03/15 16:55:42 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_switch_io(int *pipe, int *lex_id, t_lexer *l_n, t_mini *m_n)
{
	if (l_n->type == PIPE)
		(*pipe)++;
	if (l_n->type == LESS && *pipe == *lex_id && l_n->broken == 0)
		m_n->infile = open((l_n->next)->word, O_RDONLY);
	else if (l_n->type == GREATER
		&& *pipe == *lex_id && l_n->broken == 0 && (l_n->next))
		m_n->outfile = open((l_n->next)->word, 1 | O_CREAT | O_TRUNC, 0644);
	else if (l_n->type == D_GREATER && *pipe == *lex_id && l_n->broken == 0)
		m_n->outfile = open((l_n->next)->word, 1 | O_CREAT | O_APPEND, 0644);
	else if (l_n->type == D_LESS && *pipe == *lex_id)
		ft_here_doc(m_n, (l_n->next)->word);
}

int	ft_set_io(t_mini **mini, t_lexer **lexer)
{
	int		pipe;
	int		lex_id;
	t_lexer	*l_node;
	t_mini	*m_node;

	m_node = *mini;
	lex_id = 0;
	while (m_node)
	{
		pipe = 0;
		l_node = *lexer;
		while (l_node)
		{
			ft_switch_io(&pipe, &lex_id, l_node, m_node);
			l_node = l_node->next;
		}
		m_node = m_node->next;
		lex_id++;
	}
	return (0);
}

char	**ft_full_cmnd(t_lexer *lexer)
{
	t_lexer	*aux;
	char	**full_cmnd;
	int		pipe;

	pipe = 1;
	aux = lexer;
	while (aux->next && aux->next->type != PIPE)
	{
		aux = aux->next;
		if (aux->type == FLAG || aux->type == STRING)
			pipe++;
	}
	full_cmnd = malloc(sizeof(char *) * (pipe + 1));
	pipe = 0;
	aux = lexer;
	full_cmnd[pipe++] = ft_strdup(aux->word);
	while (aux->next && aux->next->type != PIPE)
	{
		aux = aux->next;
		if (aux->type == FLAG || aux->type == STRING)
			full_cmnd[pipe++] = ft_strdup(aux->word);
	}
	full_cmnd[pipe] = NULL;
	return (full_cmnd);
}

int	ft_parser(t_main *m)
{
	if (!m->lexer)
		return (1);
	ft_check_bad_input(&m->lexer, m);
	ft_to_mini_lst(&m->lexer, &m->mini, &m->envp_list);
	ft_set_io(&m->mini, &m->lexer);
	ft_set_full_cmnd(&m->mini, &m->lexer);
	ft_set_path(&m->mini, &m->lexer, &m->envp_list, m);
	return (0);
}
