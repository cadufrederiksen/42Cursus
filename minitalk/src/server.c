/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/08 15:34:49 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>
#include <sys/types.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}


void get_len(int *bit, int *len_received, int sig, char **string)//len ok!
{
	static int len = 0;
	
	if(sig == SIGUSR1)
		len += ft_recursive_power(2, *bit);
	if(*bit == 31)
	{
		*string = (char *)ft_calloc(len + 1, 1);
		*bit = 0;
		*len_received = 1;
		len = 0;
		return;
	}
	(*bit)++;		
}

void return_values(int *len_received, char **string, int *index)
{
	*len_received = 0;
	if(string)
	{
		ft_putendl_fd(*string, 1);
		free(*string);
		string = 0;
	}
	*index = 0;
}

void get_info (int sig)//descobrir como fazer um loop
{
	static char *string = 0; //string a ser devolvida
	static int bit = 0; //quantidade de bits recebidos
	static int index = 0; //posicao do array
	static int len_received = 0; //flag para saber qnd acaba len
	static int char_bit = 0; //valor char do byte
	
	if(!len_received)
		get_len(&bit, &len_received, sig, &string);
	else 
	{
		if(sig == SIGUSR1)
			char_bit += ft_recursive_power(2, bit);
		if(bit == 7)
		{
			string[index++] = char_bit;
			bit = 0;
			if(char_bit == 0)
				return (return_values(&len_received, &string, &index));
			char_bit = 0;
			return ;
		}
		bit++;	
	}			
}

int main(void)
{
	int pid;
	pid = getpid();
	ft_printf("Pid es: %d\n", pid);
	
	signal(SIGUSR1, get_info);
	signal(SIGUSR2, get_info);
	while(1)	
		usleep(100);
}
