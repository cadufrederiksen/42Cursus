/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:38:32 by isporras          #+#    #+#             */
/*   Updated: 2024/02/13 11:35:34 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_is_dir(char *path)
{
	struct stat s;
	if (stat(path, &s) == 0)
	{
		if (S_ISDIR(s.st_mode))
			return (ft_perror_mod(path, "Is a directory", 126), 1);
		return (0);
	}
	else
	{
		ft_perror(path);
		last_status = 127;
		return (1);
	}
}

char	*ft_find_cmnd_path(char **envp, char *cmnd)
{
	int		i;
	int		j;
	char	**path_split;
	char	*fullpath;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_split = ft_split(&envp[i][5], ':');
			j = 0;
			while (path_split[j])
			{
				fullpath = ft_strdup(path_split[j]);
				fullpath = ft_strjoin(fullpath, "/");
				fullpath = ft_strjoin(fullpath, cmnd);
				if (access(fullpath, F_OK) == 0)
					return (ft_free_2d(path_split), fullpath);//si encuentra hay que hacer un free de path_split
				free(fullpath);
				j++;
			}
		}
		i++;
	}
	ft_free_2d(path_split);
	return (NULL);
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

int	ft_set_path_cmnd(t_mini **mini, t_lexer **lexer, char **envp)
{
	t_mini	*aux_mini;
	t_lexer	*aux_lexer;

	aux_mini = *mini;
	aux_lexer = *lexer;
	while (aux_lexer)
	{
		if (aux_lexer->type == CMND && ft_is_builtin(aux_lexer->word) == 0)
		{
			if (ft_strchr(aux_lexer->word, '/') != NULL)
			{
				aux_mini->full_path = ft_strdup(aux_lexer->word);
				if (ft_check_is_dir(aux_mini->full_path) == 1)
					return (1);
			}
			else
				aux_mini->full_path = ft_find_cmnd_path(envp, aux_lexer->word);
			if (!aux_mini->full_path)
				return (ft_cmnd_error(aux_lexer->word, aux_mini->full_path));
			aux_mini = aux_mini->next;
		}
		else if (aux_lexer->type == CMND && ft_is_builtin(aux_lexer->word) == 1)
			aux_mini = aux_mini->next;
		aux_lexer = aux_lexer->next;
	}
	return (0);
}
