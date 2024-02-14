/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:55:30 by carmarqu          #+#    #+#             */
/*   Updated: 2024/02/14 17:47:39 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	signal_helper()
{
	rl_on_new_line();//indica al terminal que una nueva linea esta se inicializando
	rl_redisplay();//fuerza atualizacion de la linea
	ft_putchar_fd('\n', 1);
	rl_replace_line("" , 0);
	rl_on_new_line();//indica al terminal que una nueva linea esta se inicializando
	rl_redisplay();//fuerza atualizacion de la linea
	last_status = CTRL_C;
} 

void	ft_sigint(int sig)
{
	(void)sig;//Evita el warning de -Werror pero no hace realmente nada
	
	if (last_status == HEREDOC || last_status == IN_CMD)
	{	
		//printf("%d\n", last_status);
		if (last_status == HEREDOC)
			ioctl(0, TIOCSTI, "\n");
		else
			ft_putchar_fd('\n', 1);
		rl_replace_line("" , 0);
		rl_on_new_line();//indica al terminal que una nueva linea esta se inicializando
		last_status = EXIT_CMD;
	}
	else
		signal_helper();

}

int singal_init()
{
	last_status = INIT;
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	return (0);
}