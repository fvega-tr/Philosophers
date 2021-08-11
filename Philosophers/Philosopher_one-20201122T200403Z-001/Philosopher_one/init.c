/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:59 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/11 18:27:55 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_one.h"

static void	ft_init_mutex(t_struct *general)
{
	int	i;

	pthread_mutex_init(&general->write_mutex, NULL);
	pthread_mutex_init(&general->dead_mutex, NULL);
	pthread_mutex_lock(&general->dead_mutex);
	i = 0;
	while (i < general->num_philos)
		pthread_mutex_init(&general->forks_mutex[i++], NULL);
}

static void	ft_init_philos(t_struct *general)
{
	int	i;

	i = 0;
	while (i < general->num_philos)
	{
		general->philo[i].is_eating = 0;
		general->philo[i].position = i;
		general->philo[i].lfork = i;
		general->philo[i].rfork = (i + 1) % general->num_philos;
		general->philo[i].eat_count = 0;
		general->philo[i].general_link = general;
		pthread_mutex_init(&general->philo[i].mutex, NULL);
		pthread_mutex_init(&general->philo[i].eat_mutex, NULL);
		pthread_mutex_lock(&general->philo[i].eat_mutex);
		i++;
	}
}

int			ft_init(t_struct *general)
{
	if (!(general->philo = malloc(sizeof(t_struct) * general->num_philos)))
		return (1);
	ft_init_philos(general);
	if (!(general->forks_mutex = malloc(sizeof(pthread_mutex_t) *
	general->num_philos)))
		return (1);
	ft_init_mutex(general);
	return (0);
}
