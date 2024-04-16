/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:57:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/04/16 14:50:46 by lglauch          ###   ########.fr       */
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
	bool			even_turn;
	pthread_mutex_t	eat_count;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	checker_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	protect_eat;
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
	bool			allowed_to_eat;
	struct s_philo	*next;
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
void	pick_up_forks(t_philo *philo);
void	eating_check(t_philo *philo);

#endif