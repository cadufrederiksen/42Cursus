/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:52:20 by isporras          #+#    #+#             */
/*   Updated: 2024/02/19 18:45:05 by isporras         ###   ########.fr       */
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

int	ft_parser(t_lexer **lexer, t_mini **mini, t_envp **envp_list)
{
	if (!*lexer)
		return (1);
	ft_check_bad_input(lexer);
	mini = ft_to_mini_lst(lexer, mini, envp_list);
	ft_set_io(mini, lexer);
	ft_set_full_cmnd(mini, lexer);
	ft_set_path_cmnd(mini, lexer, envp_list);
	return (0);
}
