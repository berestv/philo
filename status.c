/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:15:06 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/26 17:50:15 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*status(void *philo)
{
	t_phil	*phil;

	phil = philo;
	phil->prev_meal = NULL;
	while (1)
	{
		if (phil->data.dead > 0)
			break ;
	}
}
