/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:21:49 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/14 15:49:27 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_handler(char type)
{
	if (type == 'a')
		printf("Error! Wrong number of arguments.\nUse"
		"./philo [num_philosophers] [time_to_die] [time_to_eat] "
		"[time_to_sleep] [max_meals]");
	else if (type == 'p')
		printf("Error! Wrong number of philosophers.");
	else if (type == 'd')
		printf("Error! Wrong number of philosophers.");
	return (-1);
}
