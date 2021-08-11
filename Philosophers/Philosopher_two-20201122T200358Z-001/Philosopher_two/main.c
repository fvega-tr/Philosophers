/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:20:29 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/12 18:49:56 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_two.h"

int	main(int argc, char **argv)
{
	t_struct	general;

	if (ft_check_error(&general, argc, argv))
		return (1);
	if (ft_init(&general))
		return (1);
	if (ft_create_thread(&general))
		return (1);
	sem_wait(general.dead_mutex);
	ft_clean_sem(&general);
	return (0);
}
