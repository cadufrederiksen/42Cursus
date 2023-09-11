/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:13 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/11 17:22:50 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>
#include <sys/types.h>


void send_len (pid_t pid, int len)
{
	int i;

	i = -1;
	while(++i < 32)
	{
		if(len & 1)
			kill(pid, SIGUSR1);
		else 
			kill(pid, SIGUSR2);
		len = len >> 1;
		usleep(100);
	}
}

void send_char(int bit, pid_t pid)
{
	int i;
	
	i = -1;
	while(++i < 8)
	{
		if(bit & 1)
			kill(pid, SIGUSR1);//envia 1
		else 
			kill(pid, SIGUSR2);	//envia 0
		bit = bit >> 1;
		usleep(100);
	} 
}

int main(int argc, char **argv)
{
	if (argc != 3)
		exit(0);
	pid_t pid;
	char *string;
	int i; 
	int len;

	i = -1;
	string = argv[2];
	pid = ft_atoi(argv[1]);
	len = ft_strlen(string);
	send_len(pid, len);
	while(string[++i])
		send_char(string[i], pid);
	send_char(string[i], pid);
}