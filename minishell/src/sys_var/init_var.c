/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:39:26 by isporras          #+#    #+#             */
/*   Updated: 2024/02/17 17:27:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_set_term_var(void)
{
	setenv("TERM", "xterm", 0);
}

void	ft_init_var(char **envp, t_envp **envp_list)
{
	singal_init();
	create_envp(envp_list, envp);
	ft_set_term_var();
}
