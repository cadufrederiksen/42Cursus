/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:52:20 by isporras          #+#    #+#             */
/*   Updated: 2024/02/13 11:59:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_set_io(t_mini **mini, t_lexer **lexer)
{
	int		pipe;
	int		lex_id;
	int		flag;
	t_lexer	*aux;
	t_mini	*m_node;

	flag = 0;//no falla
	m_node = *mini;
	lex_id = 0;
	while (m_node)
	{
		pipe = 0;
		aux = *lexer;
		while (aux)
		{
			if (aux->type == PIPE)
				pipe++;
			if (aux->type == LESS && pipe == lex_id && flag == 0)
			{
				m_node->infile = open((aux->next)->word, O_RDONLY);
				flag += ft_file_error(m_node->infile, (aux->next)->word);//Comprueba si ha fallado open
				//En caso de que no se abra el archivo de entrada no queremos que se tome en cuenta nada relacionado CON ESE PIPE
			}
			else if (aux->type == GREATER && pipe == lex_id)
			{
				if (aux->next)
				{
					m_node->outfile = open((aux->next)->word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
					flag += ft_file_error(m_node->outfile, (aux->next)->word);
				}
			}
			else if (aux->type == D_GREATER && pipe == lex_id)
			{
				m_node->outfile = open((aux->next)->word, O_WRONLY | O_CREAT | O_APPEND, 0644);
				flag += ft_file_error(m_node->outfile, (aux->next)->word);
			}
			else if (aux->type == D_LESS && pipe == lex_id)
				ft_here_doc(m_node, (aux->next)->word);
			aux = aux->next;
		}
		m_node = m_node->next;
		lex_id++;
	}
	return (flag);
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

int	ft_parser(t_lexer **lexer, t_mini **mini, char **envp, t_envp **envp_list)
{
	mini = ft_to_mini_lst(lexer, mini, envp_list);
	if (ft_set_io(mini, lexer) > 0)
		return (1);
	ft_set_full_cmnd(mini, lexer);
	if (ft_set_path_cmnd(mini, lexer, envp) == 1)
		return (1);
	return (-1);//En este caso ejecutamos el comando
}
