/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:07:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/22 00:39:39 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	pthread_t dead;
	pthread_t laps_n;
	int		x;

	x = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (!init_data(&data, argc, argv))
		return (1);
	while (x < data.num_philo)
	{
		pthread_create(&data.tid[x], NULL, &routine, (void *)&data.philo[x]);
		x++;
	}
	x = 0;
	if (data.num_philo > 1)
	{
		pthread_create(&dead, NULL, &ft_dead, (void *)&data);	
		pthread_create(&laps_n, NULL, &laps_count, (void *)&data);
	}
	while (x < data.num_philo)
	{
		pthread_join(data.tid[x++], NULL);
		x++;
	}
	ft_free(&data);
	return (0);
}
