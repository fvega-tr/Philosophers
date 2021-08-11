/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:51 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/09 16:48:14 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_two.h"

static int	ft_check_error2(t_struct *general)
{
	if (general->t_die < 0 || general->t_die > 20000000)
	{
		write(2, "Error : value out of range for time to die\n", 44);
		return (1);
	}
	if (general->t_sleep < 0 || general->t_sleep > 20000000)
	{
		write(2, "Error : value out of range for time to sleep\n", 46);
		return (1);
	}
	if (general->t_eat < 0 || general->t_eat > 20000000)
	{
		write(2, "Error : value out of range for time to eat\n", 44);
		return (1);
	}
	if (general->num_philos < 0 || general->num_philos > 200)
	{
		write(2, "Error : value out of range for number of philosophers\n", 55);
		return (1);
	}
	return (0);
}

int			ft_check_error(t_struct *general, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write(1, "Error: Wrong number of arguments\n", 34);
		return (1);
	}
	general->num_philos = ft_atoi(argv[1]);
	general->t_die = ft_atoi(argv[2]);
	general->t_eat = ft_atoi(argv[3]);
	general->t_sleep = ft_atoi(argv[4]);
	general->num_eat = (argc == 6) ? ft_atoi(argv[5]) : 0;
	return (ft_check_error2(general));
}
