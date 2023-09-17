/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:13 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/15 16:49:28 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_len (pid_t pid, int strlen)
{
	static int i = 0;//bits recebidos
	static int len = 0; //str len
	
	if(!len)
		len = strlen;
	i = -1;
	if(i < 32)
	{
		if(len & 1)
			kill(pid, SIGUSR1);
		else 
			kill(pid, SIGUSR2);
		len = len >> 1;
		i++;
		usleep(100);
	} 
}

void send_null(pid_t pid)
{
	static int i;

	i = 0;
	if(i <= 8)
		kill(pid, SIGUSR2);
}

void send_char(pid_t pid, char *string)
{
	static int bits = 0;//bits recebidos
	static char *str = 0; //string a ser devolvida

	bits = 0;
	if (string)
		str = string;
	ft_printf("%s\n", "aqui");
	if(*str)
	{
		if(bits < 8)
		{
			if((unsigned char)*str & 1)
				kill(pid, SIGUSR1);//envia 1
			else 
				kill(pid, SIGUSR2);	//envia 0
			*str = *str >> 1;
			bits++; 
			usleep(100);
		} 
		if (bits == 7)
		{
			bits = 0;
			(*str)++;
		}	
	}
	if(!*str)
		send_null(pid);
}

void send_info(int sig, siginfo_t *sa, void *context)
{
	static pid_t pid = 0;
	
	pid = sa->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		send_len(pid, 0);
	else if (sig == SIGUSR2)
		send_char(pid, NULL);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		exit(2);
	struct sigaction sa;
	sa.sa_sigaction = send_info;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	char *string;
	
	string = argv[2];
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_len(ft_atoi(argv[1]), ft_strlen(string));//enviar para salvar as variaveis
	send_char(ft_atoi(argv[1]), string);//enviar para salvar as variaveis
	while(1)
		usleep(100);
	return (0);
}