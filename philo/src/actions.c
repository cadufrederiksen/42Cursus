/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/14 16:07:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_msg(int status, t_philo *philo)
{
	if (philo->data->break_flag == 1)
		return ;
	pthread_mutex_lock(&philo->data->write);//esse mutex faz com que as impressoes saiam em ordem
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
	if (philo->data->break_flag == 1)
		return ;
	print_msg(2, philo);//printa que vai comer
	ft_usleep(philo->data->sleep_time);//espera
	print_msg(3, philo);//printa que ta pensando
}

void	eat(t_philo *philo)
{
	if (philo->data->break_flag == 1)
		return ;
	if (philo->id == philo->data->num_philo)
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);//trava o da frente
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	print_msg(4, philo);
	print_msg(1, philo);
	philo->last_meal = get_time() - philo->data->start_time;//essa subtracao da o num pequeno
	ft_usleep(philo->data->eat_time);
	philo->laps++;
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
}
