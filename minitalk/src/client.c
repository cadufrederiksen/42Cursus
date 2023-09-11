/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:13 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/11 17:20:04 by carmarqu         ###   ########.fr       */
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
		if(byte[i] == '1')
		{
			ft_printf("%d\n", kill(pid, SIGUSR2));
			write(1, "sent 2\n", 7);
		}
		else if (byte[i] == '0')
		{
			ft_printf("%d\n", kill(pid, SIGUSR1));
			write(1, "sent 1\n", 7);
		}
		i++;
	} 
}

void send_char(int bit, pid_t pid)
{
	int i;
	
	i = -1;
	while(++i < 8)
	{
		if (letter == 1 && flag == 0)
			byte[i--] = '0';
		else if (letter == 1 && flag == 1)
		{
			byte[i--] = '1';
			flag--;
		}
		else
		{
			byte[i] = (letter % 2) + 48;
			letter = letter / 2;
			i--;
		}
	}
	byte[8] = '\0';
	send_sig(byte, pid);
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