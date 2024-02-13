/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:55:30 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/13 11:23:39 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_sigint(int sig)
{
	sig = 0;

	rl_replace_line("" , 0);
	ft_putchar_fd('\n', 1);
	rl_on_new_line();//indica al terminal que una nueva linea esta se inicializando
	rl_redisplay();//fuerza atualizacion de la linea
}

int singal_init()
{
	signal(SIGINT, ft_sigint);
	return (0);
}