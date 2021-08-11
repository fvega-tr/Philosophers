/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:44:32 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/14 06:55:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_three.h"

static char	*ft_message2(int type)
{
	if (type == EAT)
		return (" is eating\n");
	else if (type == SLEEP)
		return (" is sleeping\n");
	else if (type == FORK)
		return (" has taken a fork\n");
	else if (type == THINK)
		return (" is thinking\n");
	else if (type == OVER)
		return ("\tNumber of meals reached\n");
	return (" died\n");
}

void		ft_message(t_philos *philo, int type)
{
	static int	done = 0;

	sem_wait(philo->general_link->write_mutex);
	if (!done)
	{
		ft_putnbr_fd(ft_get_time() - philo->general_link->start_time, 1);
		if (type != OVER)
		{
			write(1, "\tThe philosopher ", 18);
			ft_putnbr_fd(philo->position + 1, 1);
		}
		if (type >= DIED)
			done = 1;
		write(1, ft_message2(type), ft_strlen(ft_message2(type)));
	}
	sem_post(philo->general_link->write_mutex);
}
