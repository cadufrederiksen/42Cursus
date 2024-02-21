/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:43:29 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/21 16:42:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_parent(char *cmd)//cd, export y unset tienen que ser en el padre
{
	if (!cmd)
		return (0);
	else if (!ft_strncmp(cmd, "cd", 3))
		return (1);
	else if (!ft_strncmp(cmd, "export", 7))
		return (1);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (1);
	else
		return (0);
}

int	 ft_bt_parent(t_mini *mini, t_envp **envp)
{
	if (!ft_strncmp(mini->full_cmd[0], "cd", 3) && !mini->next)
		return (ft_cd(mini, envp));
	else if (!ft_strncmp(mini->full_cmd[0], "export", 7) && !mini->next)
		return (ft_export(envp, &mini->full_cmd[1]), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "unset", 6) && !mini->next)
		return (ft_unset(envp, &mini->full_cmd[1]), 1);
	return (0);
}

int	 ft_is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	else if (!ft_strncmp(cmd, "echo", 5))
		return (1);
	else if (!ft_strncmp(cmd, "pwd", 4))
		return (1);
	else if (!ft_strncmp(cmd, "cd", 3))
		return (1);
	else if (!ft_strncmp(cmd, "export", 7))
		return (1);
	else if (!ft_strncmp(cmd, "env", 4))
		return (1);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (1);
	else if (!ft_strncmp(cmd, "exit", 4))
		return (1);
	else
		return (0);
}

int	is_a_bltin(t_mini *mini)
{
	if (!mini || !mini->full_cmd)
		return (0);
	else if (!ft_strncmp(mini->full_cmd[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "export", 7))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "env", 4))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "unset", 6))
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "exit", 4))
		return (1);
	else
		return (0);
}

int	ft_builtins(t_envp **envp_list, t_mini *mini)
{
	if (!mini || !mini->full_cmd)
		return (1);
	else if (!ft_strncmp(mini->full_cmd[0], "echo", 5))
		return (ft_echo(mini->full_cmd, mini->outfile), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "pwd", 4))
		return (ft_pwd(mini->outfile), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "env", 4))
		return (ft_env(mini->outfile, envp_list, &mini->full_cmd[1]));
	else if (!ft_strncmp(mini->full_cmd[0], "cd", 3))
		return (ft_cd(mini, envp_list));
	else if (!ft_strncmp(mini->full_cmd[0], "export", 7) && !mini->next)
		return (ft_export(envp_list, &mini->full_cmd[1]), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "unset", 6) && !mini->next)
		return (ft_unset(envp_list, &mini->full_cmd[1]), 1);
	else if (!ft_strncmp(mini->full_cmd[0], "exit", 4) && !mini->next)
		return (ft_exit(mini->full_cmd), 1);
	return (1);
}
