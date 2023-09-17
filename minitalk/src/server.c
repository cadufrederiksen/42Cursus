/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/15 16:37:57 by carmarqu         ###   ########.fr       */
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

void return_string(char **string, int *index, int *len_flag)
{
	*len_flag = 0;
	if(*string)
	{
		ft_putendl_fd(*string, 1);
		free(*string);
		string = 0;
	}
	*index = 0;
}

void get_info (int sig, siginfo_t *sa, void *context)
{
	static char *string = 0;//string a ser devolvida 
	static int index = 0;//posicao na string
	static int len_flag = 0;//se recebeu ou nao len
	static int byte_char = 0;//char em numero
	static int bits_received = 0;//quantidade de bits recebidos
	int client_pid;
	
	(void)context;
	client_pid = sa->si_pid;
	if(!len_flag)
		get_len(&len_flag, &bits_received, &string, sa);
	else 
	{
		if (sig == SIGUSR1)
			byte_char += ft_recursive_power(2, bits_received);
		if(bits_received == 7)
		{//bits recebidos
			string[index++] = byte_char;
			bits_received = 0;
			if (byte_char == 0)
				return (return_string(&string, &index, &len_flag));				
			byte_char = 0;
			return ;
		}
		kill(client_pid, SIGUSR2);
		usleep(100);
		bits_received++;
	}
}

int main(void)
{
	struct sigaction	sa;
	sa.sa_sigaction = get_info;
	sa.sa_flags = SA_SIGINFO;
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
