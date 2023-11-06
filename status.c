/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:15:06 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/06 11:03:40 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*status(void *philo)
{
	t_phil	*phil;

	phil = (t_phil *)philo;
	if (phil->data->phil_no == 1)
	{
		lock_mutex(phil->lfork);
		print(phil, "has taken a fork");
		unlock_mutex(phil->lfork);
		return (NULL);
	}
	if (phil->id % 2 == 0)
		usleep(1669);
	while (phil->data->dead == 0)
	{
		if (get_forks(phil) == -1)
			return (NULL);
		if (eat(phil) == -1)
			return (NULL);
		if (p_sleep(phil) == -1)
			return (NULL);
		if (think(phil) == -1)
			return (NULL);
	}
	return (NULL);
}

int	get_forks(t_phil *phil)
{
	lock_mutex(&phil->data->mutex);
	if (phil->data->dead > 0 || phil->data->eaten == phil->data->phil_no)
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
	if (phil->data->dead > 0 || phil->data->eaten == phil->data->phil_no)
	{
		unlock_mutex(&phil->data->mutex);
		unlock_mutex(phil->lfork);
		unlock_mutex(phil->rfork);
		return (-1);
	}
	unlock_mutex(&phil->data->mutex);
	lock_mutex(&phil->bigbro);
	phil->prev_meal = get_time();
	print(phil, "is eating");
	unlock_mutex(&phil->bigbro);
	lock_mutex(&phil->data->mutex);
	phil->meal_no++;
	if (phil->data->tmeals != -1)
		if (phil->meal_no == phil->data->tmeals)
			phil->data->eaten++;
	unlock_mutex(&phil->data->mutex);
	usleep(phil->data->tteat * 1000);
	unlock_mutex(phil->lfork);
	unlock_mutex(phil->rfork);
	return (0);
}

int	p_sleep(t_phil *phil)
{
	lock_mutex(&phil->data->mutex);
	if (phil->data->dead > 0 || phil->data->eaten == phil->data->phil_no)
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
	if (phil->data->dead > 0 || phil->data->eaten == phil->data->phil_no)
	{
		unlock_mutex(&phil->data->mutex);
		return (-1);
	}
	unlock_mutex(&phil->data->mutex);
	print(phil, "is thinking");
	return (0);
}
