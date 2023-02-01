/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:01 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/01 14:54:56 by charles          ###   ########.fr       */
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

void	ft_position(t_data *s)
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
		s->p[i] = x;
	}
	i = -1;
}

void	ft_sort_big_stack(t_data *s, t_data *b)
{
	ssize_t	i;
	ssize_t	y;
	int		count;

	y = -1;
	while (ft_is_sorted(s->p, s->count))
	{
		i = -1;
		count = s->count;
		y++;
		while (++i < count)
		{
			if ((s->p[0] >> y) & 1)
				rolling(s->p, s->count, "ra\n");
			else
				push(s, b, "pb\n");
		}
		while (b->count > 0)
			push(b, s, "pa\n");
	}
}
