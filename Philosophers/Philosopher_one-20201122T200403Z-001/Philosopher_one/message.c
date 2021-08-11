/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:44:32 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/12 19:01:04 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_one.h"

static char	*ft_message2(int type)
{
	if (type == EAT)
		return (" is eating\n");
	else if (type == SLEEP)
		return (" is sleeping\n");
	else if (type == RIGHT_FORK)
		return (" has taken the right fork\n");
	else if (type == LEFT_FORK)
		return (" has taken the left fork\n");
	else if (type == THINK)
		return (" is thinking\n");
	else if (type == OVER)
		return ("\tNumber of meals reached\n");
	return (" died\n");
}

void		ft_message(t_philos *philo, int type)
{
	static int	done = 0;

	pthread_mutex_lock(&philo->general_link->write_mutex);
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
	pthread_mutex_unlock(&philo->general_link->write_mutex);
}
