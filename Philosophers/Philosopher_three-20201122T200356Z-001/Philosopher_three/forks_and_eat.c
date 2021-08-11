/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_and_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:46 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/14 06:54:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_three.h"

void	ft_drop_forks(t_philos *philo)
{
	sem_post(philo->general_link->forks_mutex);
	sem_post(philo->general_link->forks_mutex);
	usleep(philo->general_link->t_sleep * 1000);
}

void	ft_eat(t_philos *philo)
{
	sem_wait(philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = ft_get_time();
	philo->limit = philo->last_eat + philo->general_link->t_die;
	ft_message(philo, EAT);
	usleep(philo->general_link->t_eat * 100);
	philo->eat_count++;
	philo->is_eating = 0;
	sem_post(philo->mutex);
	sem_post(philo->eat_mutex);
}

void	ft_take_forks(t_philos *philo)
{
	sem_wait(philo->general_link->forks_mutex);
	ft_message(philo, FORK);
	sem_wait(philo->general_link->forks_mutex);
	ft_message(philo, FORK);
}
