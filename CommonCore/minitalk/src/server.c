/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:55:42 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/28 16:55:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

void	get_info(int sig)
{
	static int	bits = 0;
	static int	byte_value = 0;

	if (sig == SIGUSR1)
		byte_value += ft_recursive_power(2, 7 - bits);
	bits++;
	if (bits == 8)
	{
		if (!byte_value)
			write(1, "\n", 1);
		write(1, &byte_value, 1);
		bits = 0;
		byte_value = 0;
		return ;
	}
}

int	main(void)
{
	ft_printf("Pid: %d\n", getpid());
	signal(SIGUSR1, get_info);
	signal(SIGUSR2, get_info);
	while (1)
		usleep(100);
	return (0);
}
