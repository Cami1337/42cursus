/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:07:22 by leo               #+#    #+#             */
/*   Updated: 2024/04/15 19:07:10 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	t_philo			*hungriest;

	philo = (t_philo *)arg;
	arg = NULL;
	while (philo->data->run == true && philo->alive == true)
	{
		pthread_mutex_lock(&philo->data->hungriest);
		hungriest = find_hungriest_philo(philo);
		if (philo == hungriest)
		{
			if (philo->id % 2 == 0)
			{
				if (philo->eat == 0)
					precise_sleep(1);
				take_left_fork(philo);
				take_right_fork(philo);
			}
			else
			{
				take_right_fork(philo);
				take_left_fork(philo);
			}
			is_eating(philo);
			print_action(philo, "is sleeping");
			precise_sleep(philo->data->time_to_sleep);
			print_action(philo, "is thinking");
		}
		pthread_mutex_unlock(&philo->data->hungriest);
	}
	return (NULL);
}

void	create_threads(t_data *data, t_philo *philo)
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
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	pthread_create(&data->monitoring, NULL, &check_status, philo);
	while (i < data->nb_philo)
		pthread_join(philo[i++].thread, NULL);
	pthread_join(data->monitoring, NULL);
	free(data->forks);
	free(data);
	free(philo);
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
			if (finished_eating(philo))
			{
				precise_sleep(5);
				printf("finished eating\n");
				exit(0);
			}
			if (philo[i].eat == philo->data->nb_eat)
				philo[i].alive = false;
			if (philo[i].started_eating && philo[i].data->time_to_die <= get_time()
				- philo[i].time_last_meal)
			{
				philo->data->run = false;
				precise_sleep(5);
				print_action(&philo[i], "died");
				exit (0);// fix lateeeeeeeeeeeeeeeeeeeeeeer
			}
			i++;
		}
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
	return (1);
}
