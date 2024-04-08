/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:13 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/29 11:37:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

void	get_info(int sig, siginfo_t *info, void *context)
{
	static int	byte_char = 0;
	static int	bits_received = 0;
	int			client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		byte_char += ft_recursive_power(2, bits_received);
	bits_received++;
	if (bits_received == 8)
	{
		bits_received = 0;
		if (byte_char == 0)
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR2);
		}
		if (byte_char != 0)
			write(1, &byte_char, 1);
		byte_char = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	info;
	int					pid;
	
	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = get_info;
	pid = getpid();
	ft_printf("Pid es: %d\n", pid);
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		usleep(100);
	return (0);
}
