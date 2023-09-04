/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/04 16:53:12 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

void handler (int sig)
{
	ft_printf("signal: %d\n", sig);
	exit(0);
}

int main(void)
{
	int pid;
	
	pid = getpid();
	ft_printf("Pid es: %d\n", pid);
	signal(SIGUSR1, handler);
	pause();
	return (0);
}