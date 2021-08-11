/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:39 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/11 18:57:52 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_two.h"

static int	ft_dead(t_philos *philo)
{
	while (1)
	{
		sem_wait(philo->mutex);
		if (!philo->is_eating && ft_get_time() > philo->limit)
		{
			ft_message(philo, DIED);
			sem_post(philo->mutex);
			sem_post(philo->general_link->dead_mutex);
			return (0);
		}
		sem_post(philo->mutex);
	}
}

static int	ft_eat_count(t_struct *general)
{
	int i;
	int j;

	i = 0;
	while (i < general->num_eat)
	{
		j = 0;
		while (j < general->num_philos)
			sem_wait(general->philo[j++].eat_mutex);
		i++;
	}
	ft_message(&general->philo[0], OVER);
	sem_post(general->dead_mutex);
	return (0);
}

static int	ft_thread_philos(t_philos *philo)
{
	pthread_t	tid;

	philo->last_eat = ft_get_time();
	philo->limit = philo->last_eat + philo->general_link->t_die;
	if (pthread_create(&tid, NULL, (void *)ft_dead, philo))
		return (1);
	while (1)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_drop_forks(philo);
		ft_message(philo, THINK);
	}
	return (0);
}

int			ft_create_thread(t_struct *general)
{
	int			i;
	pthread_t	tid;

	i = 0;
	general->start_time = ft_get_time();
	if (general->num_eat > 0)
	{
		if (pthread_create(&tid, NULL, (void *)ft_eat_count, general))
			return (1);
		pthread_detach(tid);
	}
	while (i < general->num_philos)
	{
		if (pthread_create(&tid, NULL, (void*)ft_thread_philos,
		&general->philo[i]))
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}
