/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_and_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:46 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/11 18:25:55 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_one.h"

void	ft_drop_forks(t_philos *philo)
{
	pthread_mutex_unlock(&philo->general_link->forks_mutex[philo->lfork]);
	pthread_mutex_unlock(&philo->general_link->forks_mutex[philo->rfork]);
	usleep(philo->general_link->t_sleep * 1000);
}

void	ft_eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = ft_get_time();
	philo->limit = philo->last_eat + philo->general_link->t_die;
	ft_message(philo, EAT);
	usleep(philo->general_link->t_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_mutex);
}

void	ft_take_forks(t_philos *philo)
{
	pthread_mutex_lock(&philo->general_link->forks_mutex[philo->lfork]);
	ft_message(philo, LEFT_FORK);
	pthread_mutex_lock(&philo->general_link->forks_mutex[philo->rfork]);
	ft_message(philo, RIGHT_FORK);
}
