/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:06:26 by lglauch           #+#    #+#             */
/*   Updated: 2024/04/17 17:13:06 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	init_data(t_data *data, char **argv)
{
	int	fork_number;

	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		exit(0);
	fork_number = ft_atoi(argv[1]);
	while (--fork_number >= 0)
		pthread_mutex_init(&data->forks[fork_number], NULL);
	data->start = get_time();
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->last_meal, NULL);
	pthread_mutex_init(&data->eat_count, NULL);
	pthread_mutex_init(&data->checker_mutex, NULL);
	data->run = true;
}

int	input_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!is_int(argv[i]))
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if ((argc == 6 || argc == 5) && input_check(argc, argv))
	{
		philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (!philo)
			return (0);
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		init_data(data, argv);
		philo->data = data;
		create_threads(data, philo);
		clear_data(philo);
		return (0);
	}
	else
		printf("Error: Wrong number of arguments\n");
	return (1);
}
