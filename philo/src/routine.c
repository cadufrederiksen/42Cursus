/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/11 17:08:11 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_dead(t_philo *philo)
{
	if (philo->last_meal >= philo->data->death_time)
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

void	*routine(void *arg) 
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->break_flag != 1)
	{
		ft_dead(philo);
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
