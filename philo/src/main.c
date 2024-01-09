/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:24:32 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/09 07:24:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

void join_th(t_data *data, pthread_t *dead)
{
	int x;

	x = 0;
	while (x < data->num_philo)
	{
		pthread_join(data->tid[x], NULL);
		x++;
	}
	pthread_join(*dead, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	pthread_t dead;
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
	if (data.num_philo > 1)
		pthread_create(&dead, NULL, &ft_end, (void *)&data);
	join_th(&data, &dead);
	ft_free(&data);
	return (0);
}