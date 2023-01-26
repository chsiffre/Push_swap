/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:01 by chsiffre          #+#    #+#             */
/*   Updated: 2023/01/26 17:18:17 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_is_sorted(int *tab, size_t count)
{
	size_t	i;
	size_t	y;

	i = -1;
	while (++i < count)
	{
		y = i;
		while (++y < count)
			if (tab[i] > tab[y])
				return (1);
	}
	return (0);
}

void ft_position(t_data *s, ssize_t count)
{
	ssize_t	i;
	ssize_t	x;
	ssize_t	y;

	i = -1;
	s->p_a = malloc(count * sizeof(int));
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
		s->p_a[i] = x;
	}
	i = -1;
}

void	ft_sort_big_stack(t_data *s)
{
	ssize_t	i;
	ssize_t	y;
	int count;

	y = -1;
	while (ft_is_sorted(s->p_a, s->count))
	{
		i = -1;
		count = s->count;
		y++;
		while (++i < count)
		{
			if ((s->p_a[0] >> y) & 1)
				rolling(s->p_a, s->count, "ra\n");
			else
				pb(s);
		}
		while (s->size_pb > 0)
			pa(s);
	}
}
