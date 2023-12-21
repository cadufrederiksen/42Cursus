/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/21 18:05:31 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int dead_check(t_philo *philo)
{
	if (philo->last_meal + philo->data->death_time < (get_time() - philo->data->start_time))//se o tempo atual é menor que a ultima refeicao + o tmp de morte
	{
		pthread_mutex_lock(&philo->data->done);
		philo->data->break_flag = 1;
		pthread_mutex_unlock(&philo->data->done);
		pthread_mutex_lock(&philo->data->write);
		printf("%ld Philo %d died\n", (get_time() - philo->data->start_time), philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
	return (0);
}

void	*laps_count(void *arg)
{
	t_data *data;
	int x;

	x = 0;
	data = (t_data *)arg;
	while (data->break_flag != 1)
	{
		pthread_mutex_lock(&data->lap);
		if (data->philo[x].laps == data->final_lap)
			x++;
		else 
			x = 0;
		pthread_mutex_unlock(&data->lap);
		if (x == data->num_philo)
		{
			pthread_mutex_lock(&data->done);
			data->break_flag = 1;
			pthread_mutex_unlock(&data->done);
		}
	}
	return (0);
}

void	*ft_dead(void *arg)
{
	t_data	*data;
	int		x;

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
