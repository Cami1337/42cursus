/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:30:20 by lglauch           #+#    #+#             */
/*   Updated: 2024/04/18 12:27:13 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clear_data(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_destroy(&philo->data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print);
	pthread_mutex_destroy(&philo->data->last_meal);
	pthread_mutex_destroy(&philo->data->eat_count);
	pthread_mutex_destroy(&philo->data->checker_mutex);
	if (philo->data->forks)
		free(philo->data->forks);
	printf("free philo->data\n");
	if (philo->data)
		free(philo->data);
	printf("free philo\n");
	if (philo)
		free(philo);
	printf("free\n");
}

void	kill_philo(t_philo *philo)
{
	philo->data->run = false;
	precise_sleep(4);
	print_action(philo, "died");
	clear_data(philo);
	exit (0);
}
