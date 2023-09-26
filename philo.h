/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:29:36 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/26 17:49:32 by bbento-e         ###   ########.fr       */
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
	//pthread_t		thread;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*bigbro;
}					t_phil;

typedef struct s_data
{
	int				phil_no;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				dead;
	long long		start;
	pthread_t		*thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_phil			*phil;
}			t_data;

// Errors/Checks
int		err_handler(char type);
int		check_input(int arg, char **str);

// Inits
int		init(t_phil *phil, t_data *data, char **str, int meals);
int		init2(t_phil *phil, t_data *data, char **str, int i);

// Simulation
void	start(t_phil *phil, t_data *data);

// Mutex/Thread Ops
int		create_thread(pthread_t *thread);
int		destroy_thread(pthread_t *thread);
int		lock_mutex(pthread_mutex_t *mutex);
int		unlock_mutex(pthread_mutex_t *mutex);
int		destroy_mutex(pthread_mutex_t *mutex);

// Utils
int		ft_atoi(const char *str);

#endif
