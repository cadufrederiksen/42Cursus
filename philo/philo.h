/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:26:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/09 09:39:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		t1;
	struct s_data	*data;
	int				id;
	size_t			last_meal;
	int				laps;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		*tid;
	int				num_philo;
	int				break_flag;
	size_t			death_time;
	size_t			eat_time;
	size_t			sleep_time;
	int				final_lap;
	size_t			start_time;
	pthread_mutex_t	done;
	pthread_mutex_t	write;
	pthread_mutex_t	lap;
	pthread_mutex_t	*forks;

}					t_data;

void				print_msg(int status, t_philo *philo);
void				*routine(void *arg);
int					ft_atoi(const char *str);
size_t				get_time(void);
int					init_data(t_data *data, int argc, char **argv);
void				ft_free(t_data *data);
int					ft_usleep(size_t time);
void				think(t_philo *philo);
void				eat(t_philo *philo);
int					check_args(int argc, char **argv);
void				*check(void *arg);
void				*ft_end(void *arg);

#endif