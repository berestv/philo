/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:03:06 by bbento-e          #+#    #+#             */
/*   Updated: 2023/10/31 11:52:10 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_handler(char type)
{
	if (type == 'a')
		printf("Error! Wrong arguments.\nUse"
			   "./philo [1-200 philosophers] [time_to_die] [time_to_eat] "
			   "[time_to_sleep] ([(opt.)max_meals])\n");
	else if (type == 'm')
		printf("Error initializing mutex.");
	else if (type == 'l')
		printf("Error locking mutex.");
	else if (type == 'u')
		printf("Error unlocking mutex.");
	else if (type == 'd')
		printf("Error destroying mutex.");
	else if (type == 't')
		printf("Error creating thread.");
	else if (type == 'j')
		printf("Error destroying thread.");
	else if (type == 'x')
		printf("Program aborted.");
	return (-1);
}
