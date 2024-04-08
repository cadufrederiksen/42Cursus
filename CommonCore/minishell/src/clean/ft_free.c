/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:32:05 by isporras          #+#    #+#             */
/*   Updated: 2024/02/21 16:28:26 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	final_free(char *log, char *input, t_envp **envp)
{
	ft_free_envp_list(envp);
	free(input);
	free(log);
	clear_history();
}

void	ft_clean_log(t_main *m)
{
	if (m->log)
		free(m->log);
	m->log = NULL;
	if (m->input)
		free(m->input);
	m->input = NULL;
	if (m->split_input)
		ft_free_2d(m->split_input);
	m->split_input = NULL;
}
