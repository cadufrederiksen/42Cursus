/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:45:41 by isporras          #+#    #+#             */
/*   Updated: 2024/03/11 16:17:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_mini_lst(t_mini **mini)
{
	t_mini	*aux;

	while (*mini)
	{
		aux = (*mini)->next;
		if ((*mini)->full_cmd)
			ft_free_2d((*mini)->full_cmd);
		if ((*mini)->full_path)
			free((*mini)->full_path);
		free(*mini);
		*mini = aux;
	}
	*mini = NULL;
}

void	ft_free_lexer_lst(t_lexer **node)
{
	t_lexer	*node_aux;

	while (*node)
	{
		node_aux = (*node)->next;
		free((*node)->word);
		free(*node);
		*node = node_aux;
	}
	*node = NULL;
}

void	ft_free_envp_list(t_envp **envp)
{
	t_envp	*aux;

	while (*envp)
	{
		aux = (*envp)->next;
		free((*envp)->id);
		if ((*envp)->value)
			free((*envp)->value);
		free(*envp);
		*envp = aux;
	}
	*envp = NULL;
}

void	ft_free_lsts(t_lexer **lexer, t_mini **mini)
{
	ft_free_lexer_lst(lexer);
	ft_free_mini_lst(mini);
	lexer = NULL;
	mini = NULL;
}
