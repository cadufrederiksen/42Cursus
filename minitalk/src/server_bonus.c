/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:13 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/25 16:46:43 by carmarqu         ###   ########.fr       */
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

void get_info (int sig, siginfo_t *info, void *context)
{
	static int byte_char = 0;//char em numero
	static int bits_received = 0;//quantidade de bits recebidos
	int client_pid;
	
	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		byte_char += ft_recursive_power(2, bits_received);
	bits_received++;
	if(bits_received == 8)
	{
		if (byte_char == 0)
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR2);
		}
		if(byte_char != 0)
			write(1, &byte_char, 1);
		bits_received = 0;
		byte_char = 0;
	}
	kill(client_pid, SIGUSR1);
	usleep(100);
}

int main(void)
{
	struct sigaction	info; //definição de sigaction
	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = get_info;
	sigemptyset(&info.sa_mask);
	int pid;
	
	pid = getpid();
	ft_printf("Pid es: %d\n", pid);
	sigaction(SIGUSR1, &info, NULL);//uso de sigaction para receber o PID do remetente
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		usleep(100);
	return (0);
}