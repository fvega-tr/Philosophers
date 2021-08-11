/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_one.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:21:05 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/11 18:19:26 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_ONE_H
# define PHILOSOPHER_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define EAT 		0
# define SLEEP		1
# define THINK		2
# define LEFT_FORK	3
# define RIGHT_FORK	4
# define DIED 		5
# define OVER 		6

typedef struct		s_philos
{
	int				position;
	int				is_eating;
	int				limit;
	int				last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_struct	*general_link;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_mutex;
}					t_philos;

typedef struct		s_struct
{
	int				num_philos;
	int				t_eat;
	int				t_die;
	int				t_sleep;
	int				num_eat;
	int				start_time;
	t_philos		*philo;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead_mutex;
}					t_struct;

int					ft_check_error(t_struct *general, int argc, char **argv);
int					ft_init(t_struct *general);
int					ft_create_thread(t_struct *general);
void				ft_drop_forks(t_philos *philo);
void				ft_eat(t_philos *philo);
void				ft_take_forks(t_philos *philo);
int					ft_atoi(const char *str);
int					ft_get_time(void);
void				ft_message(t_philos *philo, int type);
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen(char *str);
void				ft_destroy_mutex(t_struct *general);

#endif
