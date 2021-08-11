/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:59 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/12 18:52:51 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_two.h"

static int	ft_init_mutex(t_struct *general)
{
	general->forks_mutex = ft_sem_open(SEMAPHORE_FORK, general->num_philos);
	general->write_mutex = ft_sem_open(SEMAPHORE_WRITE, 1);
	general->dead_mutex = ft_sem_open(SEMAPHORE_DEAD, 0);
	return (0);
}

static int	ft_init_philos(t_struct *general)
{
	int		i;
	char	semaphore[250];

	i = 0;
	while (i < general->num_philos)
	{
		general->philo[i].is_eating = 0;
		general->philo[i].position = i;
		general->philo[i].eat_count = 0;
		general->philo[i].general_link = general;
		make_semaphore_name(SEMAPHORE_PHILO, (char*)semaphore, i);
		if ((general->philo[i].mutex = ft_sem_open(semaphore, 1)) < 0)
			return (1);
		make_semaphore_name(SEMAPHORE_PHILOEAT, (char*)semaphore, i);
		if ((general->philo[i].eat_mutex = ft_sem_open(semaphore, 0)) < 0)
			return (1);
		i++;
	}
	return (0);
}

int			ft_init(t_struct *general)
{
	if (!(general->philo = malloc(sizeof(t_struct) * general->num_philos)))
		return (1);
	if (ft_init_philos(general))
		return (1);
	if (ft_init_mutex(general))
		return (1);
	return (0);
}
