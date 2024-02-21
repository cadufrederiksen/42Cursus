/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:05 by isporras          #+#    #+#             */
/*   Updated: 2024/02/19 18:20:41 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_is_dir(char *path)
{
	struct stat	s;

	if (stat(path, &s) == 0)
	{
		if (S_ISDIR(s.st_mode))
			return (ft_perror_mod(path, "Is a directory", 126), 1);
		return (0);
	}
	else
	{
		ft_perror(path);
		g_status = 127;
		return (1);
	}
}

void	ft_check_permission(char *path)
{
	if (access(path, X_OK) != 0)
		g_status = 126;
}

void	ft_broken_pipe(t_lexer **lexer, int pipe)
{
	t_lexer	*aux;
	int		lap;

	lap = 0;
	aux = *lexer;
	while (aux)
	{
		if (aux->type == PIPE)
			lap++;
		if (lap == pipe)
			aux->broken = 1;
		aux = aux->next;
	}
}

void	ft_check_bad_input(t_lexer **lexer)
{
	t_lexer	*x;
	int		pipe;

	pipe = 0;
	x = *lexer;
	while (x)
	{
		if (x->type == PIPE)
			pipe++;
		if (x->type == LESS || x->type == GREATER || x->type == D_GREATER)
		{
			if (x->broken == 0
				&& ((x->type == LESS && open((x->next)->word, 0) == -1)
					|| (x->type == GREATER
						&& open((x->next)->word, 1 | O_CREAT | O_TRUNC, 0644) == -1)
					|| (x->type == D_GREATER
						&& open((x->next)->word, 1 | O_CREAT | O_APPEND, 0644) == -1)))
			{
				ft_perror_mod((x->next)->word, strerror(errno), 1);
				ft_broken_pipe(lexer, pipe);
			}
		}
		if (x)
			x = x->next;
	}
}

int	ft_set_full_cmnd(t_mini **mini, t_lexer **lexer)
{
	t_mini	*aux_mini;
	t_lexer	*aux_lexer;

	aux_mini = *mini;
	aux_lexer = *lexer;
	while (aux_lexer)
	{
		if (aux_lexer->type == CMND)
		{
			aux_mini->full_cmd = ft_full_cmnd(aux_lexer);
			aux_mini = aux_mini->next;
		}
		aux_lexer = aux_lexer->next;
	}
	return (0);
}
