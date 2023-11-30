/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/30 16:34:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* void *routine(void *arg)
{
	
} */

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->dead_flag != 1 && philo->data->laps != philo->data->final_lap)
	{
		if(philo->data->philo[philo->id].status == 1 
				|| philo->data->philo[philo->id - 2].status == 1)
			think(philo);
		else
		{
			eat(philo);
			dream(philo);
		}
	}
	return (0);
}
