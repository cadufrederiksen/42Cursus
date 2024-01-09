/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:25:21 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/09 07:25:37 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free(t_data *data)
{
	int	x;

	x = data->num_philo - 1;
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->done);
	pthread_mutex_destroy(&data->lap);
	while (x >= 0)
	{
		pthread_mutex_destroy(&data->forks[x]);//nao sei se precisa fazer um free dos poteros		
		x--;
	}
	free(data->philo);
	free(data->tid);
	free(data->forks);
}

int	check_args(int argc, char **argv)
{
	int	x;
	int i;

	x = 1;
	while (x < argc)
	{
		i = 0;
		if (!ft_atoi(argv[x]))
			return (0);
		while(argv[x][i])
		{
			if (argv[x][i] >= '0' && argv[x][i] <= '9')
				i++;
			else
				return (0);
		}
		x++;
	}
	return (1);
}
 
int	ft_atoi(const char *str)
{
	long int	x;
	int			i;
	int			neg;

	neg = 1;
	i = 0;
	x = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return (neg * x);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000); //para fazer a conversao para milisegundos (usec)
}

int	ft_usleep (size_t time)//desse jeito conseguimos esperar o tempo certo que passamos como parametro
{
	size_t start;

	start = get_time();//guarda o tempo que começa
	while ((get_time() - start) < time)//enquanto tempo atual - tempo guardado é menor que o tempo que eu quero
		usleep(100);//espera meio segundo
	return (0);	
}
