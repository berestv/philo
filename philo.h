/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:29:36 by bbento-e          #+#    #+#             */
/*   Updated: 2023/10/31 12:14:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				phil_no;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				mealtrig;
	int				tmeals;
	int				eaten;
	int				dead;
	long long		start;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	struct s_phil	*phil;
}			t_data;

typedef struct s_phil
{
	int				id;
	int				meal_no;
	struct	s_data	*data;
	long long		prev_meal;
	pthread_t		philos;
	pthread_t		thread;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	bigbro;
}					t_phil;

// Errors/Checks
int			err_handler(char type);
int			check_food(t_data *data);
int			check_death(t_data *data);
int			check_input(int arg, char **str);

// Inits
int			init2(t_data *data, int i);
int			init(t_data *data, char **str, int meals);

// Simulation
int			eat(t_phil *phil);
int			think(t_phil *phil);
void		start(t_data *data);
void		*status(void *philo);
int			p_sleep(t_phil *phil);
int			get_forks(t_phil *phil);
void		print(t_phil *phil, char *str);

// Mutex/Thread Ops
void		*threads(void *arg);
int			join_thread(t_data *data);
int			lock_mutex(pthread_mutex_t *mutex);
int			unlock_mutex(pthread_mutex_t *mutex);
int			destroy_mutex(pthread_mutex_t *mutex);

// Time
long long	get_time(void);

// Utils
int			haslett(char **str);
int			ft_atoi(const char *str);
int			check_input(int arg, char **str);

#endif
