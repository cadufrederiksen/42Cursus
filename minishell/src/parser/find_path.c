/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:38:32 by isporras          #+#    #+#             */
/*   Updated: 2024/02/19 16:57:23 by isporras         ###   ########.fr       */
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
	while (path_split[j])
	{
		fullpath = ft_strdup(path_split[j]);
		fullpath = ft_strjoin(fullpath, "/");
		fullpath = ft_strjoin(fullpath, cmnd);
		if (access(fullpath, F_OK) == 0)
			return (ft_free_2d(path_split), fullpath);
		free(fullpath);
		j++;
	}
	ft_free_2d(path_split);
	return (NULL);
}

void	ft_set_path_cmnd2(t_lexer *aux_lexer, t_mini *aux_mini, t_envp **envp)
{
	if (ft_strchr(aux_lexer->word, '/') != NULL)
	{
		aux_mini->full_path = ft_strdup(aux_lexer->word);
		if (ft_check_is_dir(aux_mini->full_path) == 1)
			aux_mini->full_path = NULL;
		return ;
	}
	else
		aux_mini->full_path = ft_find_cmnd_path(envp, aux_lexer->word);
	if (!aux_mini->full_path)
		ft_cmnd_error(aux_lexer->word, aux_mini->full_path);
}

void	ft_set_path_cmnd(t_mini **mini, t_lexer **lexer, t_envp **envp)
{
	t_mini	*aux_mini;
	t_lexer	*aux_lexer;

	aux_mini = *mini;
	aux_lexer = *lexer;
	while (aux_lexer)
	{
		if (aux_lexer->type == CMND && ft_is_builtin(aux_lexer->word) == 0)
		{
			ft_set_path_cmnd2(aux_lexer, aux_mini, envp);
			aux_mini = aux_mini->next;
		}
		else if (aux_lexer->type == CMND)
			aux_mini = aux_mini->next;
		aux_lexer = aux_lexer->next;
	}
}
