/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/05 15:56:43 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* void *check(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while ()
	{
		
	}
	return (0);
} */

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->dead_flag != 1 && philo->data->laps != philo->data->final_lap)
	{
		if(philo->id % 2 == 0)
			ft_usleep(1);
		dream(philo);
		eat(philo);
	}
	return (0);
}
