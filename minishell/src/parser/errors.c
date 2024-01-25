/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:09:44 by isporras          #+#    #+#             */
/*   Updated: 2024/01/25 10:09:44 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cmnd_error(char *error, char *boole)
{
	if (!boole)
	{
		ft_putstr_fd("-bash: ", 2);
		ft_putstr_fd(error, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

void	ft_file_error(int infd, char *infile)
{
	if (infd == -1)
	{
		ft_putstr_fd("-bash: ", 2);
		ft_putstr_fd(infile, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
}
