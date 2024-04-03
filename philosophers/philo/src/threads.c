/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:07:22 by leo               #+#    #+#             */
/*   Updated: 2024/04/03 17:00:37 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	arg = NULL;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[(philo->id + 1) % philo->data->nb_philo]);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->id]);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->id]);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[(philo->id + 1) % philo->data->nb_philo]);
		print_action(philo, "has taken a fork");
	}
	print_action(philo, "is eating");
	philo->data->time_last_meal = get_time();
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
	pthread_mutex_unlock(&philo->data->forks[(philo->id + 1) % philo->data->nb_philo]);
	print_action(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	print_action(philo, "is thinking");
	check_status(*philo);
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
	while (i < data->nb_philo)
		pthread_join(philo[i++].thread, NULL);
}

void	check_status(t_philo philo)
{
	if (philo.data->time_to_die < get_time() - philo.data->time_last_meal)
	{
		print_action(&philo, "died");
		philo.alive = false;
		exit(0) ;
	}
}
