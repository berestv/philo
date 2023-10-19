/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:15:06 by bbento-e          #+#    #+#             */
/*   Updated: 2023/10/19 13:46:50 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*status(void *philo)
{
	t_phil	*phil;

	phil = (t_phil*)philo;
	if (phil->data->phil_no == 1)
	{
		lock_mutex(phil->lfork);
		print(phil, "has taken a fork");
		usleep(phil->data->tteat * 1000);
		unlock_mutex(phil->lfork);
		return (NULL);
	}
	if (phil->id % 2 == 0)
		usleep(2000);
	phil->prev_meal = get_time();
	while (1)
	{
		if (phil->data->dead > 0)
			break ;
		if (get_forks(phil) == -1 || eat(phil) == -1)
			break ;
		if (p_sleep(phil) == -1 || think(phil) == -1)
			break ;
	}
	return ((void *)phil);
}

int	get_forks(t_phil *phil)
{
	lock_mutex(&phil->data->mutex);
	if (phil->data->dead > 0 || phil->data->tmeals == phil->data->phil_no)
	{
		unlock_mutex(&phil->data->mutex);
		return (-1);
	}
	unlock_mutex(&phil->data->mutex);
	if (phil->id % 2 == 0)
	{
		lock_mutex(phil->rfork);
		print(phil, "has taken a fork");
		lock_mutex(phil->lfork);
		print(phil, "has taken a fork");
	}
	else
	{
		lock_mutex(phil->lfork);
		print(phil, "has taken a fork");
		lock_mutex(phil->rfork);
		print(phil, "has taken a fork");
	}
	return (0);
}

int	eat(t_phil *phil)
{
	lock_mutex(&phil->data->mutex);
	if (phil->data->dead > 0 || phil->data->tmeals == phil->data->phil_no)
	{
		unlock_mutex(&phil->data->mutex);
		unlock_mutex(phil->lfork);
		unlock_mutex(phil->rfork);
		return (-1);
	}
	unlock_mutex(&phil->data->mutex);
	lock_mutex(phil->bigbro);
	phil->prev_meal = get_time();
	print(phil, "is eating");
	if(phil->data->tmeals == phil->meal_no)
		phil->data->eaten++;
	unlock_mutex(&phil->data->mutex);
	unlock_mutex(phil->bigbro);
	usleep(phil->data->tteat * 1000);
	unlock_mutex(phil->lfork);
	unlock_mutex(phil->rfork);
	return (0);
}

int	p_sleep(t_phil *phil)
{
	lock_mutex(&phil->data->mutex);
	if (phil->data->dead > 0 || phil->data->tmeals == phil->data->phil_no)
	{
		unlock_mutex(&phil->data->mutex);
		return (-1);
	}
	unlock_mutex(&phil->data->mutex);
	print(phil, "is sleeping");
	usleep(phil->data->ttsleep * 1000);
	return (0);
}

int	think(t_phil *phil)
{
	lock_mutex(&phil->data->mutex);
	if (phil->data->dead > 0 || phil->data->tmeals == phil->data->phil_no)
	{
		unlock_mutex(&phil->data->mutex);
		return (-1);
	}
	unlock_mutex(&phil->data->mutex);
	print(phil, "is thinking");
	return (0);
}