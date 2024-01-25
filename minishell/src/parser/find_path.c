/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:38:32 by isporras          #+#    #+#             */
/*   Updated: 2024/01/25 15:27:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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