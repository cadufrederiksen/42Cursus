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
	int		i;
	int		lap;
	int		flag;
	t_lexer	*aux;
	t_mini	*m_node;

	flag = 0;//no falla
	m_node = *mini;
	lap = 0;
	while (m_node)
	{
		i = 0;
		aux = *lexer;
		while (aux)
		{
			if (aux->type == PIPE)
				i++;
			if (aux->type == LESS && i == lap)
			{
				m_node->infile = open((aux->next)->word, O_RDONLY);
				flag += ft_file_error(m_node->infile, (aux->next)->word);//Comprueba si ha fallado open
			}
			else if (aux->type == GREATER && i == lap)
			{
				m_node->outfile = open((aux->next)->word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				flag += ft_file_error(m_node->outfile, (aux->next)->word);
			}
			else if (aux->type == D_GREATER && i == lap)
			{
				m_node->outfile = open((aux->next)->word, O_WRONLY | O_CREAT | O_APPEND, 0644);
				flag += ft_file_error(m_node->outfile, (aux->next)->word);
			}
			else if (aux->type == D_LESS && i == lap)
				ft_here_doc(m_node, (aux->next)->word);
			aux = aux->next;
		}
		m_node = m_node->next;
		lap++;
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
	int		i;

	i = 1;
	aux = lexer;
	while (aux->next && aux->next->type != PIPE)
	{
		aux = aux->next;
		if (aux->type == FLAG || aux->type == STRING)
			i++;
	}
	full_cmnd = malloc(sizeof(char *) * (i + 1));
	i = 0;
	aux = lexer;
	full_cmnd[i++] = ft_strdup(aux->word);
	while (aux->next && aux->next->type != PIPE)
	{
		aux = aux->next;
		if (aux->type == FLAG || aux->type == STRING)
			full_cmnd[i++] = ft_strdup(aux->word);
	}
	full_cmnd[i] = NULL;
	return (full_cmnd);
}

int	ft_parser(t_lexer **lexer, t_mini **mini, char **envp, t_envp **envp_list)
{
	ft_types(lexer);
	mini = ft_to_mini_lst(lexer, mini, envp_list);
	if (ft_set_io(mini, lexer) > 0)
		last_status = 1;
	ft_set_full_cmnd(mini, lexer);
	if (ft_builtins(envp_list, *mini) == 1)
		return (0);
	if (ft_set_path_cmnd(mini, lexer, envp) == 1)
		last_status = 127;
	return (-1);//En este caso ejecutamos el comando
}
