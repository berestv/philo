/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:21:49 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/02 16:35:06 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * sign);
}

int	haslett(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(int arg, char **str)
{
	int	n;

	if (haslett(str) == -1)
		return (err_handler('a'));
	n = ft_atoi(str[1]);
	while (--arg > 0)
		if (ft_atoi(str[arg]) <= 0)
			return (err_handler('a'));
	if (n < 1)
		return (err_handler('a'));
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
