/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:59:45 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/14 12:46:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_print_envp_list(t_envp *envp)//borrar despues
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp != NULL)
	{
		printf("%s", tmp->id);
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
}

void	change_env(t_envp **envp, char *find, char *new_value)
{
	t_envp *aux;

	aux = *envp;
	while (aux)
	{
		if(!ft_strncmp(aux->id, find, ft_strlen(find)))
		{
			free(aux->value);
			aux->value = ft_strdup(new_value);
			break ;
		}
		aux = aux->next;
	}
}

char	*find_env(t_envp **envp, char *find)
{
	t_envp *aux;
		
	aux = *envp;
	while (aux)
	{
		if (!ft_strncmp(aux->id, find, ft_strlen(find)))
			return (aux->value);
		aux = aux->next;
	}
	return (0);
}

int cd_error(char *not_find)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(not_find, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	last_status = 1;
	return (1);
}

int	ft_cd(t_mini *mini, t_envp **envp)//se llega hasta aqui full_cmd[1] sera el camino
{
	char *pwd;
	char *oldpwd;
	char buffer[1024];
	char *dst;

	if (!mini->full_cmd[1] || !ft_strncmp(mini->full_cmd[1], " ", ft_strlen(mini->full_cmd[1])))
		dst = ft_strdup(find_env(envp, "HOME"));//cuando son muchos espacios falla
	else if (!ft_strncmp(mini->full_cmd[1], "-", ft_strlen(mini->full_cmd[1])))
		dst = ft_strdup(find_env(envp, "OLDPWD"));
	else
		dst = ft_strdup(mini->full_cmd[1]);
	oldpwd = ft_strdup(getcwd(buffer, sizeof(buffer)));
	if (chdir(dst)) //devuleve 1 se falla
	{
		free(oldpwd);
		cd_error(dst);
		free(dst);
		return (1);//escribir no such or file directory
	}
	pwd = ft_strdup(getcwd(buffer, sizeof(buffer)));
	change_env(envp, "PWD=", pwd);
	change_env(envp, "OLDPWD=", oldpwd);
	free(pwd);
	free(oldpwd);
	free(dst);
	return (0);
}
