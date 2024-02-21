/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:09:44 by isporras          #+#    #+#             */
/*   Updated: 2024/02/13 10:17:54 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_perror_mod(char *error, char *mod, int exit)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(mod, 2);
	ft_putstr_fd("\n", 2);
	g_status = exit;
}

void	ft_perror(char *error)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_syntax_error(char *error)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}

int	ft_cmnd_error(char *error, char *boole)
{
	if (!boole)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(error, 2);
		ft_putstr_fd(": command not found\n", 2);
		g_status = 127;
		return (1);
	}
	return (0);
}

int	ft_file_error(int infd, char *file)
{
	if (infd == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		g_status = 1;
		return (1);
	}
	return (0);
}
