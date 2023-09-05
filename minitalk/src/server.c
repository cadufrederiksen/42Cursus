/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/05 16:26:40 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

int byte_to_letter(char *byte)
{
	char result;
	int i;
	
	i = 0;
	result = 0;
	while(i < 8)
	{
		if (byte[i] == '0')
			i++;
		else if(byte[i] == '1')
		{
			result += ft_recursive_power(2, 7 - i);
			i++;
		}
	}
	write(1, &result, 1);
	return(0);
}

void handler (int sig)//descobrir como fazer um loop
{
	char *byte;
	static int i;
	
	i = 0;
	
	byte = (char*)malloc(9);
	if(sig == SIGUSR1)
		byte[i++] = '0';
	else 
		byte[i++] = '1';
	byte[8] = '\0';
	if (i == 8)
	{
		ft_printf("%s", "hello");
		byte_to_letter(byte);
		i = 0;
	}
}

int main(void)
{
	int pid;
	struct sigaction sa;

	pid = getpid();
	ft_printf("Pid es: %d\n", pid);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pause();
	
	return (0);
}