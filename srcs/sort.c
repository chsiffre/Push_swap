/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:01 by chsiffre          #+#    #+#             */
/*   Updated: 2023/01/17 17:39:09 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_data *s, size_t count)
{
	size_t	i;
	size_t	y;

	i = -1;
	while (++i < count)
	{
		y = i;
		while (++y < count)
		{
			if (s->tab[i] > s->tab[y])
				return (1);
		}
	}
	return (0);
}

void ft_position(t_data *s, ssize_t count)
{
	ssize_t	i;
	ssize_t	x;
	ssize_t	y;

	i = -1;
	s->pos = malloc(count * sizeof(int));
	while (++i < count)
	{
		y = 0;
		x = 0;
		while (y < count)
		{
			if (s->tab[i] > s->tab[y])
				x++;
			y++;
		}
		s->pos[i] = x;
		ft_printf("%d ", s->pos[i]);
	}
}