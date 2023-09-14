/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:38:22 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/14 16:34:42 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init(t_phil *phil, t_data *data, char **str, int meal_no)
{
	data->philo_no = atoi(str[1]);
	data->ttdie = atoi(str[2]);
	data->tteat = atoi(str[3]);
	data->ttsleep = atoi(str[4]);
	data->dead = 0;
	data->start = 0;
	data->thread = malloc(sizeof(pthread_t) * data->philo_no);
	data->phil = malloc(sizeof(t_phil) * data->philo_no);
	
}

int	main(int argc, char *argv[])
{
	t_phil	*phil;
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
			init(phil, data, argv, 0);
		else
			init(phil, data, argv, atoi(argv[5]));
	}
	else
		return (err_handler('a'));
}
