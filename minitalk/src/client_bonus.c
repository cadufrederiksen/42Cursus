/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/25 12:55:04 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_null(pid_t pid)
{
	static int i;

	i = 0;
	if(i <= 8)
		kill(pid, SIGUSR2);
	i++;
}

void send_char(pid_t pid, char *string)
{
	static int bits = 0;//bits recebidos
	static char *str = 0; //string a ser devolvida

	if (string)
		str = string;
	if(*str)
	{
		if((*str >> bits) & 1)
			kill(pid, SIGUSR1);//envia 1
		else
			kill(pid, SIGUSR2);	//envia 0
		bits++; 
		if (bits == 8)
		{
			bits = 0;
			str++;
		}	
	}
	if(!*str)
		send_null(pid);
}

void send_info(int sig, siginfo_t *info, void *context)
{
	static pid_t pid = 0;
	
	if(info->si_pid != 0)
		pid = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		send_char(pid, NULL);
	else if (sig == SIGUSR2)
		exit(0);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		exit(2);
	struct sigaction info;
	info.sa_sigaction = send_info;
	info.sa_flags = SA_SIGINFO;
	sigemptyset(&info.sa_mask);
	char *string;
	
	string = argv[2];
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	send_char(ft_atoi(argv[1]), string);//enviar para salvar as variaveis
	while(1)
		usleep(100);
	return (0);
}