/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:01:56 by isporras          #+#    #+#             */
/*   Updated: 2024/02/22 17:01:56 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	export_error(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd("cd: ", 2);
	ft_putchar_fd('`', 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("not a valid identifier\n", 2);
	g_status = 1;
	return (0);
}

int	check_errors(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '=' || str[0] == '0' || ft_atoi(str))
		return (export_error(str));
	else if (ft_strchr(str, '-'))
	{
		while (str && str[i] != '=')
		{
			if (str[i] == '-')
				return (export_error(str));
			i++;
		}
	}
	else if (!ft_strchr(str, '='))
		return (0);
	return (1);
}

void	ft_export(t_envp **envp_list, char **new_var)
{
	char	**splitted;
	char	*id;
	char	*value;
	int		x;

	x = 0;
	while (new_var[x])
	{
		if (check_errors(new_var[x]) && new_var[x])
		{
			splitted = ft_split(new_var[x], '=');
			id = ft_strdup(splitted[0]);
			id = ft_strjoin(id, "=");
			if (splitted[1])
				value = ft_strdup(splitted[1]);
			if (!find_env(envp_list, id))
				add_new_envp(envp_list, envp_new(new_var[x]));
			else
				change_env(envp_list, id, value);
			free(id);
			if (splitted[1])
				free(value);
			ft_free_2d(splitted);
		}
		x++;
	}
}
