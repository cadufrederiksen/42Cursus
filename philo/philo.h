/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:30 by carmarqu          #+#    #+#             */
/*   Updated: 2023/12/22 00:24:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo //estrutura do filosofo
{
	pthread_t t1;//identificador das threads
	struct s_data *data;// ponteiro para data
	int id;//número de id de cada philo
	size_t last_meal;//tempo da ultima refeiçao
	int laps;//numero de vezes que ja comeu
	pthread_mutex_t *l_fork;//vai apontar para o garfo da frente dentro do array fork
	pthread_mutex_t *r_fork;//aponta para o garfo à direita

}	t_philo;

typedef struct s_data
{
	t_philo *philo; //array para os filosofos
	pthread_t *tid; //array com os identificadores das threas dos philos 
	int num_philo;
	int break_flag;
	size_t death_time; //milisegundos
	size_t eat_time; //milisegundos
	size_t sleep_time;  //milisegundos
	int final_lap; //opcional
	size_t start_time; //tempo que começou o programa (milisegundos)
	pthread_mutex_t done;
	pthread_mutex_t write;
	pthread_mutex_t lap;
	pthread_mutex_t *forks; //array com mutex para os garfos
	
}	t_data;

void	*laps_count(void *arg);
void	print_msg(int status, t_philo *philo);
void	*routine(void *arg);
int		ft_atoi(const char *str);
size_t	get_time(void);
int		init_data(t_data *data, int argc, char **argv);
void	ft_free(t_data *data);
int		ft_usleep (size_t time);
void	dream(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);
int		check_args(int argc, char **argv);
void	*check(void *arg);
void	*ft_dead(void *arg);

#endif