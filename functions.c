/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:05:20 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/28 16:13:40 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_phil *phil, char *str)
{
	long long	time;

	time = get_time() - phil->data->start;
	pthread_mutex_lock(&phil->data->print);
	printf("%lld %d %s\n", time, phil->id, str);
	pthread_mutex_unlock(&phil->data->print);
}