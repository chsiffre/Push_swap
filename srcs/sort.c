/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:01 by chsiffre          #+#    #+#             */
/*   Updated: 2023/01/18 18:15:17 by charles          ###   ########.fr       */
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
			if (s->p_a[i] > s->p_a[y])
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
			if (s->p_a[i] > s->p_a[y])
				x++;
			y++;
		}
		s->pos[i] = x;
	}
}

void	ft_sort_big_stack(t_data *s)
{
	ssize_t	count;
	ssize_t	i;
	ssize_t	y;

	y = -1;
	while (!ft_is_sorted(s, s->count))
	{
		i = -1;
		count = s->count;
		y++;
		while (++i < count)
			if ((s->p_a[0] >> y) && 1)
				pb(s);
			else
				rolling(s->p_a, count, "ra\n");
	}
		while (s->size_pb >= 0)
			pa(s);
}