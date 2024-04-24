/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:33:07 by leo               #+#    #+#             */
/*   Updated: 2024/04/22 11:01:34 by jkauker          ###   ########.fr       */
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

void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}
	else
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
}
