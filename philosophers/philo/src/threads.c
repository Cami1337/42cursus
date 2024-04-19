/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:07:22 by leo               #+#    #+#             */
/*   Updated: 2024/04/19 14:31:26 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	arg = NULL;
	while (philo->data->run == true && philo->alive == true)
	{
		pick_up_forks(philo);
		if (philo->data->run == false)
			return (NULL);
		is_eating(philo);
		if (philo->data->run == false)
			return (NULL);
		print_action(philo, "is sleeping");
		precise_sleep(philo->data->time_to_sleep);
		if (philo->data->run == false)
			return (NULL);
		print_action(philo, "is thinking");
	}
	return (NULL);
}

int	create_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].alive = true;
		philo[i].eat = 0;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].started_eating = false;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
			return (1);
		precise_sleep(1);
		i++;
	}
	i = 0;
	if (pthread_create(&data->monitoring, NULL, &check_status, philo))
		return (1);
	while (i < data->nb_philo)
		pthread_join(philo[i++].thread, NULL);
	pthread_join(data->monitoring, NULL);
	return (0);
}

void	*check_status(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->checker_mutex);
	while (philo->data->run == true)
	{
		i = 0;
		while (i < philo->data->nb_philo)
		{
			finished_eating(philo);
			if (philo[i].eat == philo->data->nb_eat)
				philo[i].alive = false;
			if (philo[i].started_eating && philo[i].data->time_to_die
				<= get_time() - philo[i].time_last_meal)
				if (kill_philo(&philo[i]))
					return ((void *)1);
			i++;
		}
		if (philo->data->run == false)
			break ;
	}
	pthread_mutex_unlock(&philo->data->checker_mutex);
	return (NULL);
}

int	precise_sleep(int milliseconds)
{
	long	start;

	start = get_time();
	while (get_time() - start < milliseconds)
	{
		usleep(250);
	}
	return (1);
}

int	finished_eating(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->data->nb_eat == -1)
		return (0);
	while (i < philo->data->nb_philo)
	{
		if (philo[i].eat < philo->data->nb_eat)
			return (0);
		i++;
	}
	precise_sleep(4);
	printf("finished eating\n");
	clear_data(philo);
	free(philo);
	exit (0);
	return (1);
}
