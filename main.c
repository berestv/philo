/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:38:22 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/06 11:01:18 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_data *data, char **str, int meals)
{
	int	i;

	i = 0;
	if (data->mealtrig == 1 && meals <= 0)
		return (err_handler('a'));
	data->phil_no = ft_atoi(str[1]);
	data->ttdie = ft_atoi(str[2]);
	data->tteat = ft_atoi(str[3]);
	data->ttsleep = ft_atoi(str[4]);
	data->start = get_time();
	if (pthread_mutex_init(&data->mutex, NULL) != 0)
		return (err_handler('m'));
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (err_handler('m'));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->phil_no);
	while (i < data->phil_no)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (err_handler('m'));
		i++;
	}
	init2(data, meals);
	return (0);
}

int	init2(t_data *data, int i)
{
	if (data->mealtrig == 1)
		data->tmeals = i;
	else
		data->tmeals = -1;
	i = 0;
	data->eaten = 0;
	data->dead = 0;
	data->start = get_time();
	data->phil = malloc(sizeof(t_phil) * data->phil_no);
	while (i < data->phil_no)
	{
		data->phil[i].id = i + 1;
		data->phil[i].prev_meal = get_time();
		data->phil[i].meal_no = 0;
		data->phil[i].lfork = &data->forks[i];
		if (data->phil_no > 1)
			data->phil[i].rfork = &data->forks[(i + 1) % data->phil_no];
		data->phil[i].data = data;
		if (pthread_mutex_init(&data->phil[i].bigbro, NULL) != 0)
			return (err_handler('m'));
		i++;
	}
	return (0);
}

void	start(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_no)
	{
		if (pthread_create(&data->phil[i].thread, NULL,
				&status, &data->phil[i]) != 0)
			err_handler('t');
		usleep(800);
		i++;
	}
	if (pthread_create(&data->thread, NULL,
			&threads, data) != 0)
		err_handler('t');
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if ((argc == 5 || argc == 6) && check_input(argc, argv) != -1)
	{
		if (argc == 5)
		{
			data.mealtrig = -1;
			init(&data, argv, 0);
		}
		else
		{
			data.mealtrig = 1;
			init(&data, argv, atoi(argv[5]));
		}
		start(&data);
		join_thread(&data);
		free(data.forks);
		free(data.phil);
	}
	else if (argc != 5 && argc != 6)
		return (err_handler('a'));
	else
		return (0);
}
