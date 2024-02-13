/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:29:47 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/13 10:15:50 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void 	echo_flag (char **cmd, int *flag, int *x)
{
	int i;

	while (cmd[*x])
	{
		if (cmd[*x] && !ft_strncmp(cmd[*x], "-n", 2))//compara si empeza con -n
		{
			i = 2;
			while (cmd[*x][i] == 'n' && cmd[*x][i])//checkea si hasta el final solo hay n
				i++;
			if (i != ft_strlen(cmd[*x]))
			{
				printf("hola\n");
				return ;
			}
			*flag = 1;
		}
		else	
			return ;
		(*x)++;
	}
	
}

void	ft_echo(char **cmd, int fd)
{
	int x;
	int i;
	int flag;

	x = 1;
	flag = 0;
	echo_flag(cmd, &flag, &x);//checkea si hay flag y cuantas
	while (cmd[x])
	{
		i = 0;
		while(cmd[x][i])
		{
			write(fd, &cmd[x][i], 1);
			i++;	
		}
		if (cmd[x + 1])
			write(fd, " ", 1);
		x++;
	}
	if (!flag)
		write(fd, "\n", 1);
}
