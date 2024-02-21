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

void	ft_clean_log(char *log, char *input, char **split_input)
{
	free(log);
	free(input);
	ft_free_2d(split_input);
}
