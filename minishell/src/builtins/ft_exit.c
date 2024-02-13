/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:32:01 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/12 15:04:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exit(char **cmd)
{
	printf("exit\n");
	if (ft_atoi(cmd[0]) && cmd[1])
	{
		ft_putstr_fd("bash: exit: too many arguments", 2);
		last_status = 1;
		return ;
	}
	if (cmd[0])
	{
		if (ft_atoi(cmd[0]))
			exit(ft_atoi(cmd[0]));
		else 
		{
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(cmd[0], 2);
			ft_putchar_fd(':', 2);
			ft_putstr_fd(" numeric argument required", 2);
			exit(255);
		}
	}
	else 
		exit(last_status);
}
