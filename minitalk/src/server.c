/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:23:15 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/11 14:42:16 by carmarqu         ###   ########.fr       */
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


void get_len(int *len_flag, int *bits_received, char **string, int sig)
{
	static int len = 0;
	
	if(sig == SIGUSR1)
		len += ft_recursive_power(2, *bits_received);
	if (*bits_received == 31)
	{
		*string = malloc(len + 1);
		*bits_received = 0;
		*len_flag = 1;
		len = 0;
		return ;
	}
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

void get_info (int sig)
{
	static char *string = 0;//string a ser devolvida 
	static int index = 0;//posicao na string
	static int len_flag = 0;//se recebeu oou nao len
	static int byte_char = 0;//char em numero
	static int bits_received = 0;//quantidade de bits recebidos
	
	if(!len_flag)
		get_len(&len_flag, &bits_received, &string, sig);
	else 
	{
		if (sig == SIGUSR1)
			byte_char += ft_recursive_power(2, bits_received);
		if(bits_received == 7)
		{
			string[index++] = byte_char;
			bits_received = 0;
			if (byte_char == 0)
				return(return_string(&string, &index, &len_flag));				
			byte_char = 0;
			return ;
		}
		bits_received++;
	}
	
}

int main(void)
{
	int pid;

	pid = getpid();
	ft_printf("Pid es: %d\n", pid);
	//mudar nome do handler
	signal(SIGUSR1, get_info);
	signal(SIGUSR2, get_info);
	while(1)
		usleep(100);
}
