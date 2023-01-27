/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:01 by chsiffre          #+#    #+#             */
/*   Updated: 2023/01/27 14:44:32 by charles          ###   ########.fr       */
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

void ft_position(t_data *s)
{
	ssize_t	i;
	ssize_t	x;
	ssize_t	y;

	i = -1;
	while (++i < s->count)
	{
		y = 0;
		x = 0;
		while (y < s->count)
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

	y = -1;
	while (ft_is_sorted(s->p_a, s->count))
	{
		i = -1;
		y++;
		while (++i < s->count)
		{
			if ((s->p_a[0] >> y) & 1)
				rolling(s->p_a, s->count, "ra\n");
			else
			{
				write(1, "pb\n", 3);
				push(s->p_a, s->p_b, s->count, s->size_pb);
			}
		}
		while (s->size_pb > 0)
		{
			write(1, "pa\n", 3);
			push(s->p_b, s->p_a, s->size_pb, s->count);
		}
	}
}
