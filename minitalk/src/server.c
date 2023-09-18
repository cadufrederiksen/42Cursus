/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/18 15:36:47 by carmarqu         ###   ########.fr       */
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

/* 
void get_len(int *len_flag, int *bits_received, char **string, siginfo_t *sa)
{
	static int len = 0;
	
	if(sa->si_signo == SIGUSR1)
		len += ft_recursive_power(2, *bits_received);
	if (*bits_received == 31)
	{
		*string = malloc(len + 1);
		*bits_received = 0;
		*len_flag = 1;
		len = 0;
		return ;
	}
	kill(sa->si_pid, SIGUSR1);
	usleep(100);
	(*bits_received)++;	
}	
 */

void get_info (int sig, siginfo_t *sa, void *context)
{
	static int byte_char = 0;//char em numero
	static int bits_received = 0;//quantidade de bits recebidos
	int client_pid;
	
	(void)context;
	client_pid = sa->si_pid;
	if (sig == SIGUSR1)
		byte_char += ft_recursive_power(2, bits_received);
	bits_received++;
	if(bits_received == 8)
	{
		bits_received = 0;
		if (byte_char == 0)
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR2);
		}
		if(byte_char != 0)
			write(1, &byte_char, 1);
		byte_char = 0;
	}
	kill(client_pid, SIGUSR1);
	usleep(100);
}

int main(void)
{
	struct sigaction	sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_info;
	sigemptyset(&sa.sa_mask);
	int pid;
	
	pid = getpid();
	ft_printf("Pid es: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}
