/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:28:38 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/18 14:46:09 by bbento-e         ###   ########.fr       */
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

int	create_thread(pthread_t *thread)
{
	if (pthread_create(thread) != 0)
		return (err_handler('t'));
	return (0);
}

int	destroy_thread(pthread_t *thread)
{
	if (pthread_join(thread, NULL) != 0)
		return (err_handler('j'));
	return (0);
}
