/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:33:07 by leo               #+#    #+#             */
/*   Updated: 2024/04/15 18:56:13 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock
		(&philo->data->forks[(philo->id % philo->data->nb_philo)]);
	print_action(philo, "has taken a fork");
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[(philo->id - 1)]);
	print_action(philo, "has taken a fork");
}

void	is_eating(t_philo *philo)
{
	print_action(philo, "is eating");
	precise_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock
		(&philo->data->forks[(philo->id) % philo->data->nb_philo]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_lock(&philo->data->last_meal);
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&philo->data->last_meal);
	pthread_mutex_lock(&philo->data->eat_count);
	philo->started_eating = true;
	philo->eat++;
	pthread_mutex_unlock(&philo->data->eat_count);
}

t_philo	*find_hungriest_philo(t_philo *philo)
{
	int		i;
	t_philo	*hungriest;

	i = 1;
	hungriest = &philo[0];
	while (i < philo->data->nb_philo)
	{
		if (philo[i].time_last_meal < hungriest->time_last_meal ||
            (philo[i].time_last_meal == hungriest->time_last_meal && philo[i].id < hungriest->id))
			hungriest = &philo[i];
		i++;
	}
	return (hungriest);
}
