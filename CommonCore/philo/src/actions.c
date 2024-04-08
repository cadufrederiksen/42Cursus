/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:23:22 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/24 14:28:19 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_msg(int status, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->done);
	if (philo->data->break_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->done);
		return ;
	}
	pthread_mutex_unlock(&philo->data->done);
	pthread_mutex_lock(&philo->data->write);
	if (status == 1)
		printf("%ld %d is eating\n", (get_time() - philo->data->start_time), philo->id);
	if (status == 2)
		printf("%ld %d is sleeping\n", (get_time() - philo->data->start_time), philo->id);
	if (status == 3)
		printf("%ld %d is thinking\n", (get_time() - philo->data->start_time), philo->id);
	if (status == 4)
	{
		printf("%ld %d has taken a fork\n", (get_time() - philo->data->start_time), philo->id);
		printf("%ld %d has taken a fork\n", (get_time() - philo->data->start_time), philo->id);
	}
	pthread_mutex_unlock(&philo->data->write);
}

void	eat(t_philo *philo)
{
	if(philo->id % 2 == 0 && philo->laps == 0)//se é um philo com id par espere um pouco
	{
		pthread_mutex_unlock(&philo->data->write);
		printf("%ld %d is thinking\n", 
			(get_time() - philo->data->start_time), philo->id);
		pthread_mutex_unlock(&philo->data->write);
		ft_usleep(100);
		
	}
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	print_msg(4, philo);
	print_msg(1, philo);
	pthread_mutex_lock(&philo->data->lap);
	philo->laps++;
	philo->last_meal = get_time() - philo->data->start_time;//essa subtracao da o num pequeno
	pthread_mutex_unlock(&philo->data->lap);
	ft_usleep(philo->data->eat_time);
	print_msg(2, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	ft_usleep(philo->data->sleep_time);
	print_msg(3, philo);
}
