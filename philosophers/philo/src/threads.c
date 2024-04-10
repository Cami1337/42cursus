/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:07:22 by leo               #+#    #+#             */
/*   Updated: 2024/04/10 19:37:16 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	static int		i = 0;

	philo = (t_philo *)arg;
	arg = NULL;
	while (philo->data->run == true && philo->alive == true)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->data->forks[(philo->id - 1)]);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(&philo->data->forks[(philo->id) % philo->data->nb_philo]);
			print_action(philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&philo->data->forks[(philo->id) % philo->data->nb_philo]);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(&philo->data->forks[(philo->id - 1)]);
			print_action(philo, "has taken a fork");
		}
		philo->time_last_meal = get_time();
		print_action(philo, "is eating");
		philo->started_eating = true;
		philo->eat++;
		precise_sleep(philo->data->time_to_sleep);
		pthread_mutex_unlock(&philo->data->forks[(philo->id) % philo->data->nb_philo]);
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		print_action(philo, "is sleeping");
		precise_sleep(philo->data->time_to_sleep);
		print_action(philo, "is thinking");
		}
		precise_sleep(10);
		if (philo->eat == philo->data->nb_eat)
			i++;
		printf("i = %d\n", i);
		if (i == philo->data->nb_philo)
		{
			printf("all philo ate %d times\n", philo->data->nb_eat);
			exit (1); // free later
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
			if (philo[i].eat == philo->data->nb_eat)
				philo[i].alive = false;
			if (philo[i].started_eating && philo[i].data->time_to_die <= get_time()
				- philo[i].time_last_meal)
			{
				philo->data->run = false;
				print_action(&philo[i], "died blaa");
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
