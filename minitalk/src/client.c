/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:08:32 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/25 17:08:44 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void send_byte(int c, pid_t pid)
{
	int bits;

	bits = 7;
	while(bits >= 0)
	{
		if((c >> bits) & 1)
			kill(pid, SIGUSR1); //envia 1
		else
			kill(pid, SIGUSR2); //envia 0
		usleep(50);
		bits--;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
		exit (0);
	int i;
	char *str;

	str = argv[2];
	i = 0;
	while(str[i])
	{
		send_byte(str[i], ft_atoi(argv[1]));
		i++;
	}
	send_byte(0, ft_atoi(argv[1]));//enviar caracter nulo
	return (0);
}