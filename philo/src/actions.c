/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/06 15:26:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_msg(int status, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	if (status == 1)
		printf("%ld Philo %d is eating\n", (get_time() - philo->data->start_time), philo->id);
	if (status == 2)
		printf("%ld Philo %d is sleeping\n", (get_time() - philo->data->start_time), philo->id);
	if (status == 3)
		printf("%ld Philo %d is thinking\n", (get_time() - philo->data->start_time), philo->id);
	if (status == 4)
	{
		printf("%ld Philo %d has taken a l_fork\n", (get_time() - philo->data->start_time), philo->id);
		printf("%ld Philo %d has taken a r_fork\n", (get_time() - philo->data->start_time), philo->id);
	}
	pthread_mutex_unlock(&philo->data->write);
}

void	dream(t_philo *philo)
{
	ft_usleep(1);
	if (philo->status == 2)
	{
		print_msg(2, philo);
		ft_usleep(philo->data->sleep_time);
	}
	else if (philo->status != 3)
		print_msg(3, philo);
	philo->status = 3;
}

void drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	//printf("%ld Philo %d has dropped a r_fork\n", (get_time() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(philo->r_fork);
	//printf("%ld Philo %d has dropped a l_fork\n", (get_time() - philo->data->start_time), philo->id);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);//trava o garfo que está a frente;
	print_msg(4, philo);
	print_msg(1, philo);
}

void	eat(t_philo *philo)
{
	philo->status = 1;
	take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	ft_usleep(philo->data->eat_time);
	//philo->last_meal = get_time() - philo->data->start_time;
	if (philo->id == philo->data->num_philo)
		philo->data->laps++;
	philo->status = 2;
	pthread_mutex_unlock(&philo->lock);
	drop_fork(philo);
}
