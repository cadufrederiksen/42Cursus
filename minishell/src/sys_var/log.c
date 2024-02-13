/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:36:48 by isporras          #+#    #+#             */
/*   Updated: 2024/02/05 12:36:48 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_refresh_log()
{
	char	*log;
	char	buffer[1024];

	log = ft_strjoin_nofree(getenv("USER"), "@minishell ~");
	log = ft_strjoin(log, getcwd(buffer, sizeof(buffer)));
	log = ft_strjoin(log, "> ");
	return (log);
}
