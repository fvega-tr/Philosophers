/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_three.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:52:27 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/14 17:52:30 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_THREE_H
# define PHILOSOPHER_THREE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <string.h>
# include <signal.h>

# define SEMAPHORE_FORK		"SemaphoreFork"
# define SEMAPHORE_WRITE	"SemaphoreWrite"
# define SEMAPHORE_DEAD		"SemaphoreDead"
# define SEMAPHORE_PHILO	"SemaphorePhilo"
# define SEMAPHORE_PHILOEAT	"SemaphorePhiloEat"

# define EAT 		0
# define SLEEP		1
# define THINK		2
# define FORK		3
# define DIED 		4
# define OVER 		5

typedef struct		s_philos
{
	pid_t			pid;
	int				position;
	int				is_eating;
	int				limit;
	int				last_eat;
	int				eat_count;
	struct s_struct	*general_link;
	sem_t			*mutex;
	sem_t			*eat_mutex;
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
	sem_t			*forks_mutex;
	sem_t			*write_mutex;
	sem_t			*dead_mutex;
}					t_struct;

int					ft_check_error(t_struct *general, int argc, char **argv);
int					ft_init(t_struct *general);
int					ft_create_forks(t_struct *general);
void				ft_drop_forks(t_philos *philo);
void				ft_eat(t_philos *philo);
void				ft_take_forks(t_philos *philo);
int					ft_atoi(const char *str);
int					ft_get_time();
void				ft_message(t_philos *philo, int type);
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen(char *str);
sem_t				*ft_sem_open(char const *name, int value);
char				*make_semaphore_name(char const *base, char *buffer,
					int position);
void				ft_clean_sem(t_struct *general);
void				ft_kill(t_struct *general);

#endif
