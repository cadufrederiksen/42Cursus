/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/29 11:55:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(pid_t pid)
{
	static int	i;

	i = 0;
	if (i < 8)
		kill(pid, SIGUSR2);
	i++;
}

void	send_char(pid_t pid, char *string)
{
	static int	bits = 0;
	static char	*str = 0;

	if (string)
		str = string;
	if (*str)
	{
		if ((*str >> bits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits++;
		if (bits == 8)
		{
			bits = 0;
			str++;
		}
	}
	else
		send_null(pid);
}

void	send_info(int sig, siginfo_t *info, void *context)
{
	static pid_t	pid;

	pid = 0;
	if (info->si_pid != 0)
		pid = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		send_char(pid, NULL);
	else if (sig == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	info;

	if (argc != 3)
		exit(2);
	info.sa_sigaction = send_info;
	info.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	send_char(ft_atoi(argv[1]), argv[2]);
	while (1)
		usleep(100);
	return (0);
}
