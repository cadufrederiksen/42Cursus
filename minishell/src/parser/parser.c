/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:52:20 by isporras          #+#    #+#             */
/*   Updated: 2024/01/24 15:06:23 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_set_io(t_mini *m_node, t_lexer **lexer, int lap)
{
	int	i;
	t_lexer	*aux;

	aux = *lexer;
	i = 0;
	while (aux)
	{
		if (aux->type == PIPE)
			i++;
		if (aux->type == LESS && i == lap)
			m_node->infile = open((aux->next)->word, O_RDONLY);
		if (aux->type == GREATER && i == lap)
			m_node->outfile = open((aux->next)->word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		aux = aux->next;
	}
	if (m_node->infile == -1 || m_node->outfile == -1)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
}

void	ft_error(char *error, char *boole, int errint)
{
	if (!boole)
	{
		errno = errint;
		perror(error);
	}

}

char	**ft_full_cmnd(t_lexer *lexer)
{
	t_lexer	*aux;
	char	**full_cmnd;
	int		i;

	i = 1;
	aux = lexer;
	while (aux->next && aux->next->type == FLAG)
	{
		aux = aux->next;
			i++;
	}
	full_cmnd = malloc(sizeof(char *) * (i + 1));
	i = 0;
	aux = lexer;
	full_cmnd[i++] = ft_strdup(aux->word);
	while (aux->next && aux->next->type == FLAG)
	{
		aux = aux->next;
		full_cmnd[i++] = ft_strdup(aux->word);
	}
	full_cmnd[i] = NULL;
	return (full_cmnd);
}

t_mini	**ft_parser(t_lexer **lexer, t_mini **mini, char **envp)
{
	ft_types(lexer);
	mini = ft_to_mini_lst(lexer, mini, envp);
	return (mini);
}
