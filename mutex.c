/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:28:38 by bbento-e          #+#    #+#             */
/*   Updated: 2023/10/23 12:29:31 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		return (err_handler('l'));
	return (0);
}

int	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
		return (err_handler('u'));
	return (0);
}

int	destroy_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
		return (err_handler('d'));
	return (0);
}

int	join_thread(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->thread, NULL) != 0)
		return (err_handler('j'));
	while (i < data->phil_no)
	{
		if (pthread_join(data->phil[i].thread, NULL) != 0)
		return (err_handler('j'));
		usleep(100);
		i++;
	}
	i = 0;
	while (i < data->phil_no)
	{
		destroy_mutex(&data->forks[i]);
		destroy_mutex(&data->phil[i].bigbro);
		i++;
	}
	destroy_mutex(&data->print);
	destroy_mutex(&data->mutex);
	return (0);
}
