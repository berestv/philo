/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:38:22 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/18 17:03:57 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_phil *phil, t_data *data, char **str)
{
	data->philo_no = ft_atoi(str[1]);
	data->ttdie = ft_atoi(str[2]);
	data->tteat = ft_atoi(str[3]);
	data->ttsleep = ft_atoi(str[4]);
	data->dead = 0;
	data->start = 0;
	data->thread = malloc(sizeof(pthread_t) * data->philo_no);
	data->phil = malloc(sizeof(t_phil) * data->philo_no);
	if (pthread_mutex_init(data->mutex, NULL) != 0)
		return (err_handler('m'));
	if (pthread_mutex_init(data->print, NULL) != 0)
		return (err_handler('m'));
	if (pthread_mutex_init(data->forks, NULL) != 0)
		return (err_handler('m'));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_phil	*phil;
	t_data	*data;

	if ((argc == 5 || argc == 6) && check_input(argc, argv) == 1)
	{
		if (argc == 5)
			init(phil, data, argv, 0);
		else
			init(phil, data, argv, atoi(argv[5]));
	}
	else
		return (err_handler('a'));
}
