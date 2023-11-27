/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/27 23:05:09 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int mail = 0;

void *routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	philo->id = 0;
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(philo->l_fork);//tentar usar um mutex das structs
		mail++;
		pthread_mutex_unlock(philo->l_fork);
	}
	return (0); 
}

int	main(int argc, char **argv)
{
	t_data	data;

	int x;

	x = 0;
	if (argc != 5 && argc != 6)
			return (1);
	init_data(&data, argc, argv);
	while (x < data.num_philo) 
	{
		pthread_create(&data.tid[x], NULL, &routine, (void *)&data.philo[x]);
		x++;
	}
	x = 0;
	while (x < data.num_philo)
	{
		pthread_join(data.tid[x], NULL);
		x++;
	}
	free_mutex(&data);
	printf("%d\n", mail);
	return (0);	
}
