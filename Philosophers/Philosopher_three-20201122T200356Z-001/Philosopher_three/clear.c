/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:43:59 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/14 17:53:19 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_three.h"

void	ft_clean_sem(t_struct *general)
{
	int		i;
	char	semaphore[255];

	sem_unlink(SEMAPHORE_FORK);
	sem_unlink(SEMAPHORE_WRITE);
	sem_unlink(SEMAPHORE_DEAD);
	if (general->philo)
	{
		i = 0;
		while (i < general->num_philos)
		{
			make_semaphore_name(SEMAPHORE_PHILO, (char*)semaphore, i);
			sem_unlink(semaphore);
			make_semaphore_name(SEMAPHORE_PHILOEAT, (char*)semaphore, i++);
			sem_unlink(semaphore);
		}
		free(general->philo);
	}
}

void	ft_kill(t_struct *general)
{
	int i;

	i = 0;
	while (i < general->num_philos)
		kill(general->philo[i++].pid, SIGKILL);
}
