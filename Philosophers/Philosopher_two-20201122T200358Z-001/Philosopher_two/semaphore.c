/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvega-tr <fvega-tr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:22:12 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/11/12 18:55:58 by fvega-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_two.h"

sem_t		*ft_sem_open(char const *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

static int	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}

static	int	ft_size(unsigned int un)
{
	unsigned int size;

	size = 1;
	while (un > 9)
	{
		un /= 10;
		size++;
	}
	return (size);
}

char		*make_semaphore_name(char const *base, char *buffer, int position)
{
	int		i;
	int		final;
	char	size;

	i = ft_strcpy(buffer, base);
	size = (ft_size(position) + i - 1);
	final = size + 1;
	while (size >= i)
	{
		buffer[size--] = (position % 10) + '0';
		position /= 10;
	}
	buffer[final] = 0;
	return (buffer);
}
