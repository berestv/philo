/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:21:49 by bbento-e          #+#    #+#             */
/*   Updated: 2023/09/19 17:01:16 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_handler(char type)
{
	if (type == 'a')
		printf("Error! Something went wrong with the arguments given.\nUse"
			"./philo [1-200 philosophers] [time_to_die] [time_to_eat] "
			"[time_to_sleep] ([max_meals])");
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
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		negative;

	i = 0;
	result = 0;
	negative = ft_see_spaces(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0')
	{
		result *= negative;
		return (result);
	}
	return (-1);
}

int	check_input(int arg, char **str)
{
	int	n;

	n = ft_atoi(str[1]);
	while (arg-- > 0)
		if (ft_atoi(str[arg]) == -1)
			return (-1);
	if (n < 1 || n > 200)
		return (-1);
	return (0);
}
