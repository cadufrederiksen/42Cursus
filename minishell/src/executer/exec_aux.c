/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:37:06 by isporras          #+#    #+#             */
/*   Updated: 2024/03/15 18:03:14 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_init_data_exec(t_mini **mini, t_exec **exec)
{
	*exec = malloc(sizeof(t_exec));
	if (!*exec)
		return (ft_perror_mod("malloc error", "exec", 1), 1);
	(*exec)->aux = *mini;
	if (!(*exec)->aux)
		return (1);
	(*exec)->total_cmnds = (*exec)->aux->total_cmnds;
	(*exec)->tmpin = dup(STDIN_FILENO);
	(*exec)->tmpout = dup(STDOUT_FILENO);
	(*exec)->i = 0;
	return (0);
}

void	ft_close_restore(t_exec *exec)
{
	dup2(exec->tmpin, STDIN_FILENO);
	close(exec->tmpin);
	dup2(exec->tmpout, STDOUT_FILENO);
	close(exec->tmpout);
}

int	size_envp(t_envp **envp)
{
	t_envp	*aux;
	int		size;

	size = 0;
	aux = *envp;
	while (aux)
	{
		aux = aux->next;
		size++;
	}
	return (size);
}

char	**envp_to_str(t_envp **envp_list)
{
	t_envp	*aux;
	char	**envp;
	int x;

	x = 0;
	envp = (char **)malloc((size_envp(envp_list) + 1) * sizeof(char *));
	aux = *envp_list;
	while (aux)
	{
		envp[x] = strdup(aux->id);
		ft_strjoin(envp[x], aux->value);
		x++;
	}
	return (envp);
}
