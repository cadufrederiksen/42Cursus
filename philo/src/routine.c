/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:24:59 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/09 09:37:50 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	case_one(t_data *data)
{
	data->break_flag = 1;
	pthread_mutex_lock(&data->write);
	printf("%ld Philo 1 has taken a fork\n", (get_time() - data->start_time));
	ft_usleep(data->death_time);
	printf("%ld Philo 1 died\n", (get_time() - data->start_time));
	pthread_mutex_unlock(&data->write);
}

void dead_check(t_philo *philo)
{
	int lm;

 	pthread_mutex_lock(&philo->data->lap);
	lm = philo->last_meal;
	pthread_mutex_unlock(&philo->data->lap);
	if (lm + philo->data->death_time < (get_time() - philo->data->start_time))
	{
		pthread_mutex_lock(&philo->data->done);
		philo->data->break_flag = 1;
		pthread_mutex_unlock(&philo->data->done);
		pthread_mutex_lock(&philo->data->write);
		printf("%ld Philo %d died\n", (get_time() - philo->data->start_time), philo->id);
		pthread_mutex_unlock(&philo->data->write);
	}
}

void	ft_laps(t_data *data)
{
	if (data->final_lap == -1)
		return ;
	int x;
	int end;

	end = 0;
	x = 0;
	while (x < data->num_philo)
	{
		pthread_mutex_lock(&data->lap);
		if (data->philo[x].laps >= data->final_lap)
			end++;
		pthread_mutex_unlock(&data->lap);
		x++;
	}	
	if (end == data->num_philo)
	{
		pthread_mutex_lock(&data->done);
		data->break_flag = 1;
		pthread_mutex_unlock(&data->done);
	}
}

void	*ft_end(void *arg)
{
	t_data	*data;
	int		x;
	int		flag;

	flag = 0;
	x = 0;
	data = (t_data *)arg;
	while (flag != 1)
	{
		ft_laps(data);
		dead_check(&data->philo[x]);
		x++;
		if (x == data->num_philo - 1)
			x = 0;
		pthread_mutex_lock(&data->done);
		flag = data->break_flag;
		pthread_mutex_unlock(&data->done);
	}
	return (0);
}

void	*routine(void *arg) 
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philo == 1)
		case_one(philo->data);
	while (1)
	{
		pthread_mutex_lock(&philo->data->done);
		if (philo->data->break_flag == 1)
		{
			pthread_mutex_unlock(&philo->data->done);
			break ;
		}
		pthread_mutex_unlock(&philo->data->done);
		eat(philo);
		//dream(philo);
	}
	return (0);
}
