/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:31:16 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/09 12:27:35 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(int fd)
{
	char buffer[1024];
	char *pwd;
	int i;

	i = 0;
	pwd = ft_strdup(getcwd(buffer, sizeof(buffer)));
	while (pwd[i])
	{
		write(fd, &pwd[i], 1);
		i++;
	}
	write(fd, "\n", 1);
	free(pwd);
}