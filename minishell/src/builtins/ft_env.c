/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:31:41 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/07 14:23:04 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		env_error(char *wrong)//en el subject pone sin argumento o opciones
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(wrong, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("No such file or directory\n", 2);
	return (1);
}

int	ft_env(int fd, t_envp **envp_list, char **cmd)//no actualiza PWD y OLDPWD cuando hace env
{
	int i;
	t_envp *aux;

	aux = *envp_list;
	if (cmd[0])
		return (env_error(cmd[0]));
	while (aux != NULL)
	{
		i = 0;
		while (aux->id[i])
		{
			write(fd, &aux->id[i], 1);
			i++;
		}
		i = 0;
		while (aux->value[i])
		{
			write(fd, &aux->value[i], 1);
			i++;
		}
		write(fd, "\n", 1);
		aux = aux->next;
	}
	return (0);
}