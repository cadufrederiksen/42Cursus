/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:55:30 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/14 13:18:11 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_sigint(int sig)
{
	(void)sig;//Evita el warning de -Werror pero no hace realmente nada
	sig = 0;
	
	if (last_status == HEREDOC)
	{
		ioctl(0, TIOCSTI, '\n');
	}	
	rl_replace_line("" , 0);
	ft_putchar_fd('\n', 1);
	rl_on_new_line();//indica al terminal que una nueva linea esta se inicializando
	rl_redisplay();//fuerza atualizacion de la linea
}

int singal_init()
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	return (0);
}