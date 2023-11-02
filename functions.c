/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:05:20 by bbento-e          #+#    #+#             */
/*   Updated: 2023/10/31 13:19:28 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_phil *phil, char *str)
{
	long long	time;

	lock_mutex(&phil->data->mutex);
	if (phil->data->dead >= 1 || &phil->data->eaten == &phil->data->phil_no)
		return ((void)unlock_mutex(&phil->data->mutex));
	unlock_mutex(&phil->data->mutex);
	time = get_time() - phil->data->start;
	pthread_mutex_lock(&phil->data->print);
	printf("%lld %i %s\n", time, phil->id, str);
	pthread_mutex_unlock(&phil->data->print);
}

void	*threads(void *arg)
{
	t_data *data;
	data = (t_data *)arg;
	while (1)
	{
		if (check_death(data) == -1)
			return (NULL);
		if (check_food(data) == -1)
			return (NULL);
	}
	return (NULL);
}

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_no)
	{
		lock_mutex(&data->phil->bigbro);
		if((get_time() - data->phil[i].prev_meal) > data->ttdie)
		{
			print(&data->phil[i], "died");
			lock_mutex(&data->mutex);
			data->dead = 1;
			unlock_mutex(&data->mutex);
			unlock_mutex(&data->phil[i].bigbro);
			return (-1);
		}
		unlock_mutex(&data->phil[i].bigbro);
		i++;
	}
	return (0);
}

int check_food(t_data *data)
{
	if (data->tmeals == -1)
		return (0);
	lock_mutex(&data->mutex);
	if (data->eaten == data->phil_no)
	{
		unlock_mutex(&data->mutex);
		return (-1);
	}
	unlock_mutex(&data->mutex);
	return (0);
}
