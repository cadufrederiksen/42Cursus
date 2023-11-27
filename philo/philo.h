/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:30 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/27 15:35:45 by carmarqu         ###   ########.fr       */
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
    int id; //número de id de cada philo
    int laps;
    int last_meal; //tempo da ultima refeiçao
    pthread_t t1; //identificador das threads
    struct s_data *data;// ponteiro para data
    pthread_mutex_t lock;
    pthread_mutex_t *l_fork; // vai apontar para o garfo da esquerda dentro do array fork
    pthread_mutex_t *r_fork;
     
    
}   t_philo;

typedef struct s_data
{
    t_philo *philo; //array para os filosofos
    pthread_t *tid; //array com os identificadores das threas dos philos 
    
    int num_philo;
    int death_time; //milisegundos
    int eat_time; //milisegundos
    int sleep_time;  //milisegundos
    int eat_final; //opcional
    size_t start_time; //tempo que começou o programa (milisegundos)
    pthread_mutex_t *forks; //array com mutex para os garfos
    
} t_data;

void *routine(void *arg);
int	ft_atoi(const char *str);
size_t get_time(void);
int init_data(t_data *data, int argc, char **argv);
void free_mutex(t_data *data);

#endif