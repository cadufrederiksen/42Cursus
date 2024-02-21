/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:37:06 by isporras          #+#    #+#             */
/*   Updated: 2024/02/20 17:37:06 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_init_data_exec(t_mini **mini, t_exec **exec)
{
	*exec = malloc(sizeof(t_exec));
	if (!*exec)
		return (ft_perror_mod("malloc error", "exec", 1), g_status);
	(*exec)->aux = *mini;
	if (!(*exec)->aux)
		return (g_status);
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
