/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:15:06 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/28 16:02:38 by bbento-e         ###   ########.fr       */
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
		if (get_forks(phil->data) == -1)
			break ;
	}
}

int	get_forks(t_data *data)
{
	pthread_mutex_lock(data->phil->lfork);
	ft_print(root, "has taken a fork");
	return (0);
}