/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:57:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/04/15 18:49:19 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define MAX_INTER 2147483647
# define MIN_INTER -2147483648

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	long			start;
	int				run;
	pthread_mutex_t	eat_count;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	checker_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	hungriest;
	pthread_t		monitoring;	
}					t_data;

typedef struct s_philo
{
	bool			alive;
	int				eat;
	int				sleep;
	int				think;
	int				id;
	long			time_last_meal;
	bool			started_eating;
	t_data			*data;
    pthread_t		thread;
}					t_philo;

int		ft_atoi(const char *str);
long	get_time(void);
void	print_action(t_philo *philo, char *action);
int		is_int(const char *str);
void	create_threads(t_data *data, t_philo *philo);
void	*routine(void *arg);
void	*check_status(void *arg);
int		precise_sleep(int milliseconds);
int		finished_eating(t_philo *philo);
void	take_left_fork(t_philo *philo);
void	take_right_fork(t_philo *philo);
void	is_eating(t_philo *philo);
t_philo	*find_hungriest_philo(t_philo *philo);

#endif