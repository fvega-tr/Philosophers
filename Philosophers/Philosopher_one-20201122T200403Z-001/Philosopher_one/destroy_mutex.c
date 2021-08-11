/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:11:37 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/09 19:48:59 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_one.h"

void	ft_destroy_mutex(t_struct *general)
{
	int	i;

	if (general->forks_mutex)
	{
		i = 0;
		while (i < general->num_eat)
			pthread_mutex_destroy(&general->forks_mutex[i++]);
		free(general->forks_mutex);
	}
	if (general->philo)
	{
		i = 0;
		while (i < general->num_philos)
		{
			pthread_mutex_destroy(&general->philo[i].mutex);
			pthread_mutex_destroy(&general->philo[i++].eat_mutex);
		}
		free(general->philo);
	}
	pthread_mutex_destroy(&general->write_mutex);
	pthread_mutex_destroy(&general->dead_mutex);
}
