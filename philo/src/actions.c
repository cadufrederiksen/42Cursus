/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/30 16:35:18 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	dream(t_philo *philo)
{
	printf("%ld Philo %d is sleeping\n", (get_time() - philo->data->start_time), philo->id);
	philo->status = 2;
	ft_usleep(philo->data->sleep_time);
}

void	think(t_philo *philo)
{
	if (philo->status != 3)
		printf("%ld Philo %d is thinking\n", (get_time() - philo->data->start_time), philo->id);
	philo->status = 3;
}

void drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);//trava o garfo que está a frente;
	printf("%ld Philo %d has taken a l_fork\n", (get_time() - philo->data->start_time), philo->id);
	pthread_mutex_lock(philo->r_fork);
	printf("%ld Philo %d has taken a r_fork\n", (get_time() - philo->data->start_time), philo->id);
}

void	eat(t_philo *philo)
{
	philo->status = 1;
	take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = get_time() - philo->data->start_time;
	printf("%d Philo %d is eating\n", philo->last_meal, philo->id);
	ft_usleep(philo->data->eat_time);
	if (philo->id == philo->data->num_philo)
		philo->data->laps++;
	pthread_mutex_unlock(&philo->lock);
	drop_fork(philo);
}
