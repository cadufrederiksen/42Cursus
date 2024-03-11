/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:39:10 by carmarqu          #+#    #+#             */
/*   Updated: 2024/03/11 16:53:58 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	unset_node(t_envp *aux)
{
	t_envp	*tmp;

	if (aux->next->next)
	{
		tmp = aux->next->next;
		free(aux->next->id);
		free(aux->next->value);
		free(aux->next);
		aux->next = tmp;
	}
	else
	{
		free(aux->next->id);
		free(aux->next->value);
		free(aux->next);
		aux->next = NULL;
	}
}

void	unset_first(t_envp **envp)
{
	t_envp	*tmp;
	
	tmp = (*envp)->next;
	free((*envp)->id);
	free((*envp)->value);
	free((*envp));
	*envp = NULL;
	*envp = tmp;
}

void	unset_error(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd("cd: ", 2);
	ft_putchar_fd('`', 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("not a valid identifier\n", 2);
}

void	ft_unset_helper(t_envp **envp, char *id)
{
	t_envp *aux;

	aux = *envp;
	if (!ft_strncmp(aux->id, id, ft_strlen(id)))
		unset_first(envp);
	while (aux)
	{
		if (aux->next && !ft_strncmp(aux->next->id, id, ft_strlen(id)))
		{
			unset_node(aux);
			return ;
		}
		aux = aux->next;
	}
}

void	ft_unset(t_envp **envp, char **args)
{
	int		x;
	char	*id;

	x = 0;
	while (args[x])
	{
		if (!ft_strchr(args[x], '='))
		{
			id = ft_strdup(args[x]);
			id = ft_strjoin(id, "=");
			if (find_env(envp, id))
				ft_unset_helper(envp, id);
			free(id);
		}
		else
			unset_error(args[x]);
		x++;
	}
}
