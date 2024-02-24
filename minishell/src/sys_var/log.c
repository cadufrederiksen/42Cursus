/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:36:48 by isporras          #+#    #+#             */
/*   Updated: 2024/02/21 16:30:46 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_refresh_log(t_main *main)
{
	char	buffer[1024];
	
	main->log = ft_strdup(find_env(&main->envp_list, "USER"));
	main->log = ft_strjoin(main->log, "@minishell ~");
	main->log = ft_strjoin(main->log, getcwd(buffer, sizeof(buffer)));
	main->log = ft_strjoin(main->log, "> ");
	return (main->log);
}
