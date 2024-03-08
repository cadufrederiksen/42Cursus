/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:38:32 by isporras          #+#    #+#             */
/*   Updated: 2024/03/08 16:10:02 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_find_cmnd_path(t_envp **envp, char *cmnd)
{
	int		j;
	char	**path_split;
	char	*fullpath;

	j = 0;
	if (!cmnd || !cmnd[0])
		return (NULL);
	path_split = ft_split(find_env(envp, "PATH="), ':');
	while (path_split && path_split[j])
	{
		fullpath = ft_strdup(path_split[j]);
		fullpath = ft_strjoin(fullpath, "/");
		fullpath = ft_strjoin(fullpath, cmnd);
		if (access(fullpath, F_OK) == 0)
			return (ft_free_2d(path_split), fullpath);
		free(fullpath);
		j++;
	}
	if (path_split)
		ft_free_2d(path_split);
	return (NULL);
}

void	set_aux(t_lexer *aux_lexer, t_mini *aux_mini, t_envp **envp, t_main *m)
{
	if (ft_strchr(aux_lexer->word, '/') != NULL)
	{
		aux_mini->full_path = ft_strdup(aux_lexer->word);
		m->exit_status = ft_check_is_dir(aux_mini->full_path);
		if (m->exit_status != 0)
			aux_mini->full_path = NULL;
		return ;
	}
	else
	{
		if (find_env(envp, "PATH="))
			aux_mini->full_path = ft_find_cmnd_path(envp, aux_lexer->word);
	}
	if (!aux_mini->full_path)
		m->exit_status = ft_cmnd_error(aux_lexer->word, aux_mini->full_path);
}

void	ft_set_path(t_mini **mini, t_lexer **lexer, t_envp **envp, t_main *m)
{
	t_mini	*aux_mini;
	t_lexer	*aux_lexer;

	aux_mini = *mini;
	aux_lexer = *lexer;
	while (aux_lexer)
	{
		if (aux_lexer->type == CMND && ft_is_builtin(aux_lexer->word) == 0)
		{
			set_aux(aux_lexer, aux_mini, envp, m);
			aux_mini = aux_mini->next;
		}
		else if (aux_lexer->type == CMND)
			aux_mini = aux_mini->next;
		aux_lexer = aux_lexer->next;
	}
}
