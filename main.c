/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:38:22 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/25 18:12:27 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_phil *phil, t_data *data, char **str, int meals)
{
	int	i;

	i = 0;
	data->phil_no = ft_atoi(str[1]);
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
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_no);
	while (i < data->phil_no)
	{
		if (pthread_mutex_init(data->forks[i], NULL) != 0)
			return (err_handler('m'));
		i++;
	}
	init2(phil, data, str, meals);
	return (0);
}

int	init2(t_phil *phil, t_data *data, char **str, int i)
{
	if (i >= 1)
		phil->meal_no = i;
	i = 0;
	data->phil = malloc(sizeof(t_phil) * data->phil_no);
	while (i < data->phil_no)
	{
		phil[i].id = i;
		phil[i].meal_no = 0;
		phil[i].lfork = data->forks[i];
		phil[i].rfork = data->forks[(i + 1) % data->phil_no];
		if (pthread_mutex_init(phil[i], NULL) != 0)
			return (err_handler('m'));
		i++;
	}
	phil->prev_meal = 0;
	if (pthread_mutex_init(phil->rfork, NULL) != 0)
		return (err_handler('m'));
	if (pthread_mutex_init(phil->lfork, NULL) != 0)
		return (err_handler('m'));
	if (pthread_mutex_init(phil->bigbro, NULL) != 0)
		return (err_handler('m'));
}

void	start(t_phil *phil, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_no)
	{
		if (pthread_create(&data->phil, NULL, ))
	}
}

int	main(int argc, char *argv[])
{
	t_phil	*phil;
	t_data	*data;

	if ((argc == 5 || argc == 6) && check_input(argc, argv) == 1)
	{
		if (argc == 5)
			init(phil, data, argv, -1);
		else
			init(phil, data, argv, atoi(argv[5]));
		start(phil, data);
	}
	else
		return (err_handler('a'));
}
