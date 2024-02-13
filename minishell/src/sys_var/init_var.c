/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:39:26 by isporras          #+#    #+#             */
/*   Updated: 2024/01/30 12:14:53 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_set_term_var()
{
	setenv("TERM", "xterm", 0);
}

void	ft_init_var(char **envp, t_envp **envp_list)
{
	create_envp(envp_list, envp);
	ft_set_term_var();
}