/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:43:29 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/12 15:41:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


int		is_a_bltin(t_mini *mini)
{
	if (!mini || !mini->full_cmd)
		return (0);//hacer con que las funciones devuelvam -1 si hay error
	else if (!ft_strncmp(mini->full_cmd[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "export", 7))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "env", 4))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "unset", 6))
		return (1);
 	else if(!ft_strncmp(mini->full_cmd[0], "exit", 4))
		return (1);
	else
		return (0);
}

int		ft_builtins(t_envp **envp_list, t_mini *mini)//hacer como un filtro para saber se es un builtin y cual es
{
	//printf("id %dpassou\n", mini->id);
	if(is_a_bltin(mini->next))
		return (ft_builtins(envp_list, mini->next));
	if (!mini || !mini->full_cmd)
		return (0);//hacer con que las funciones devuelvam -1 si hay error
	else if (!ft_strncmp(mini->full_cmd[0], "echo", 5))
		return (ft_echo(mini->full_cmd, mini->outfile), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "cd", 3))
		return (ft_cd(mini, envp_list));
	else if (!ft_strncmp(mini->full_cmd[0], "pwd", 4))
		return (ft_pwd(mini->outfile), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "export", 7))
		return (ft_export(envp_list, &mini->full_cmd[1]), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "env", 4))
		return (ft_env(mini->outfile, envp_list, &mini->full_cmd[1]));
	else if (!ft_strncmp(mini->full_cmd[0], "unset", 6))
		return (ft_unset(envp_list, &mini->full_cmd[1]), 1);
 	else if(!ft_strncmp(mini->full_cmd[0], "exit", 4))
		return (ft_exit(&mini->full_cmd[1]), 1);
	return (0);
}