/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:59:45 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/26 16:59:46 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print_envp_list(t_envp *envp)//borrar despues
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
	t_envp	*aux;

	aux = *envp;
	while (aux)
	{
		if (!ft_strncmp(aux->id, find, ft_strlen(find)))
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
	t_envp	*aux;

	aux = *envp;
	while (aux)
	{
		if (!ft_strncmp(aux->id, find, ft_strlen(aux->id) - 1))
			return (aux->value);
		aux = aux->next;
	}
	return (0);
}

int	cd_error(char *not_find)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(not_find, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

int	ft_cd(t_mini *mini, t_envp **envp)
{
	char	*pwd;
	char	*oldpwd;
	char	buffer[1024];
	char	*dst;

	dst = ft_strdup(find_env(envp, "HOME"));
	if (mini->full_cmd[0][0] == '-' && ft_strlen(mini->full_cmd[0]) == 1)
	{
		free(dst);
		dst = ft_strdup(find_env(envp, "OLDPWD"));
	}
	else if (ft_count_lines2d(mini->full_cmd) > 2)
		return (ft_perror_mod("cd", "too many arguments", 1), 1);
	else if (mini->full_cmd[1] != NULL)
	{
		free(dst);
		dst = ft_strdup(mini->full_cmd[1]);
	}
	oldpwd = ft_strdup(getcwd(buffer, sizeof(buffer)));
	if (chdir(dst))
	{
		free(oldpwd);
		cd_error(dst);
		free(dst);
		return (1);//exit status
	}
	pwd = ft_strdup(getcwd(buffer, sizeof(buffer)));
	change_env(envp, "PWD=", pwd);
	change_env(envp, "OLDPWD=", oldpwd);
	free(pwd);
	free(oldpwd);
	free(dst);
	return (0);
}
