/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:32:01 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/26 18:15:54 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exit(char **cmd, int exit_sts)
{
	if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("bash: exit: too many arguments", 2);
		return ;
	}
	if (cmd[1])
	{
		if (ft_atoi(cmd[1]) != 0)
		{
			exit(ft_atoi(cmd[1]));
		}
		else
		{
			ft_perror_mod("exit", "numeric argument required", 2);
			exit(2);
		}
	}
	else
		exit(exit_sts);
}
