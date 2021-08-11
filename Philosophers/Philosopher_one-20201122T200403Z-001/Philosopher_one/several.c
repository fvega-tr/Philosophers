/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   several.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:22:59 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/11 18:21:51 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_one.h"

int			ft_get_time(void)
{
	static struct timeval	t;
	int						time;

	gettimeofday(&t, NULL);
	time = (int)((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (time);
}

int			ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		neg;

	neg = 1;
	i = 0;
	num = 0;
	while (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32))
		i++;
	if ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			neg *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * neg);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int aux;

	aux = n;
	if (aux < 0)
	{
		aux *= -1;
		ft_putchar_fd(45, fd);
	}
	if (aux > 9)
	{
		ft_putnbr_fd(aux / 10, fd);
		ft_putnbr_fd(aux % 10, fd);
	}
	if (aux >= 0 && aux <= 9)
		ft_putchar_fd(aux + 48, fd);
}

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
