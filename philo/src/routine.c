/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/15 13:14:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int dead_check(t_philo *philo)
{
	if (philo->data->sleep_time + philo->data->eat_time > philo->data->death_time)//se o tempo de comer e dormir juntos forem maior que o tempo de morrer
	{
		ft_usleep(philo->data->death_time);	
		pthread_mutex_lock(&philo->data->done);
		philo->data->break_flag = 1;
		pthread_mutex_unlock(&philo->data->done);
		pthread_mutex_lock(&philo->data->write);
		printf("%ld Philo %d died\n", (get_time() - philo->data->start_time), philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
	if (philo->last_meal + (get_time() - philo->data->start_time) > philo->data->death_time )//caso padrao de demorar para(nao sei se realmente ocorre)
	{
		pthread_mutex_lock(&philo->data->done);
		philo->data->break_flag = 1;
		pthread_mutex_unlock(&philo->data->done);
		pthread_mutex_lock(&philo->data->done);
		philo->data->break_flag = 1;
		pthread_mutex_unlock(&philo->data->done);
		pthread_mutex_lock(&philo->data->write);
		printf("%ld Philo %d died\n", (get_time() - philo->data->start_time), philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
	return (0);
}

void	*ft_dead(void *arg)
{
	t_data *data;
	int x;

	x = 0;
	data = (t_data *)arg;
	while (data->break_flag != 1)
	{
		dead_check(&data->philo[x]);
		x++;
		if (x == data->num_philo - 1)
			x = 0;
	}
	return (0);
}	

void	*routine(void *arg) 
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->break_flag != 1)
	{
		if ((philo->id % 2 == 0 || philo->id == philo->data->num_philo) && philo->laps == 0)
		{
			print_msg(3, philo);
			ft_usleep(philo->data->eat_time);
		}
		eat(philo);
		dream(philo);
	}
	return (0);
}
