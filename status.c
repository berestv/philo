/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:15:06 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/29 15:20:24 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*status(void *philo)
{
	t_phil	*phil;

	phil = (t_phil*)philo;
	phil->prev_meal = get_time();
	while (1)
	{
		if (phil->data->dead >= 0)
			break ;
		if (get_forks(phil) == -1)
			break ;
	}
	return ((void *)phil);
}

int	get_forks(t_phil *phil)
{
	pthread_mutex_lock(phil->lfork);
	print(phil, "has taken a fork");
	if (phil->bigbro)
	if (phil->data->phil_no == 1)
	{
		usleep(phil->data->tteat * 1000);
		return (-1);
	}
	return (0);
}

void	sleeping(t_phil *phil)
{
	print(phil, "is eating");
	usleep(phil->data->ttsleep * 1000);
}