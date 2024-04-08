/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:07:22 by leo               #+#    #+#             */
/*   Updated: 2024/04/08 16:54:01 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	arg = NULL;
	while (philo->data->run == true && philo->alive == true)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->data->forks[(philo->id)]);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(&philo->data->forks[(philo->id + 1) % philo->data->nb_philo]);
			print_action(philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&philo->data->forks[(philo->id + 1) % philo->data->nb_philo]);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(&philo->data->forks[(philo->id)]);
			print_action(philo, "has taken a fork");
		}
		print_action(philo, "is eating");
		philo->data->time_last_meal = get_time();
		philo->eat++;
		precise_sleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->data->forks[(philo->id + 1) % philo->data->nb_philo]);
		pthread_mutex_unlock(&philo->data->forks[philo->id]);
		print_action(philo, "is sleeping");
		precise_sleep(philo->data->time_to_sleep);
		print_action(philo, "is thinking");
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
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	printf("Data->run threads: %d\n", data->run);
	pthread_create(&data->monitoring, NULL, &check_status, &philo);
	while (i < data->nb_philo)
		pthread_join(philo[i++].thread, NULL);
	pthread_join(data->monitoring, NULL); /////terminate threats orm utexes important
}

void	*check_status(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *)arg;
	data = philo->data;
	printf ("Philo run : %d\n",data->run); //this is not working run not true
	printf("lololsksksksolol\n");
	while (data->run == true)
	{
		i = 0;
		printf("sssssssss\n");
		while (i < philo->data->nb_philo)
		{
			printf("lolololol\n");
			if (philo[i].eat == philo->data->nb_eat)
				philo[i].alive = false;
			if (philo[i].data->time_to_die <= get_time() - philo[i].data->time_last_meal)
			{
				philo->data->run = false;
				print_action(&philo[i], "died");
				break;
			}
		i++;
		}
	}
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
