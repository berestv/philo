/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:29:36 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/18 17:04:21 by bbento-e         ###   ########.fr       */
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

typedef struct s_phil
{
	int				id;
	int				meal_no;
	t_data			*data;
	long long		prev_meal;
	pthread_t		philos;
	pthread_t		thread;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*bigbro;
}					t_phil;

typedef struct s_data
{
	int				philo_no;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				dead;
	long long		start;
	pthread_t		*thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	forks;
	t_philo			*phil;
}			t_data;

// Errors/Checks
int		err_handler(char type);
int		check_input(int arg, char **str);

// Inits
int		init(t_phil *phil, t_data *data, char **str);

// Mutex/Thread Ops
int		create_thread(pthread_t *thread);
int		destroy_thread(pthread_t *thread);
int		lock_mutex(pthread_mutex_t *mutex);
int		unlock_mutex(pthread_mutex_t *mutex);
int		destroy_mutex(pthread_mutex_t *mutex);

// Utils
int		ft_atoi(const char *str);

#endif
