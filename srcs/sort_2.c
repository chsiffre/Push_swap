/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:56:29 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/01 14:21:24 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_stack(t_data *s, t_data *b)
{
	int	size;
	int	i;

	if (s->count == 2)
		rolling(s->p, s->count, "ra\n");
	else if (s->count == 3)
		sort_three(s);
	else if (s->count == 4)
		sort_four(s, b);
	size = s->count;
	i = -1;
	while (size > ++i)
	{
		if (s->p[0] < 2)
			push(s, b, "pb\n");
		else
			rolling(s->p, s->count, "ra\n");
	}
	if (b->p[0] == 0)
		ft_swaap(b->p, b->count, "sb\n");
	sort_three(s);
	while (b->count)
		push(b, s, "pa\n");
}

void	sort_three(t_data *s)
{
	if (s->p[0] > s->p[1] && s->p[1] < s->p[2]
		&& s->p[2] < s->p[0])
		return (rolling(s->p, s->count, "ra\n"));
	if (s->p[0] > s->p[1] && s->p[1] < s->p[2]
		&& s->p[2] > s->p[0])
		return (ft_swaap(s->p, s->count, "sa\n"));
	if (s->p[0] < s->p[1] && s->p[1] > s->p[2]
		&& s->p[2] < s->p[0])
		return (rev_rolling(s->p, s->count));
	if (s->p[0] < s->p[1] && s->p[1] > s->p[2]
		&& s->p[2] > s->p[0])
	{
		ft_swaap(s->p, s->count, "sa\n");
		return (rolling(s->p, s->count, "ra\n"));
	}
	if (s->p[0] > s->p[1] && s->p[1] > s->p[2])
	{
		ft_swaap(s->p, s->count, "sa\n");
		return (rev_rolling(s->p, s->count));
	}
}

void	sort_four(t_data *s, t_data *b)
{
	if (ft_is_sorted(s->p, s->count))
	{
		push(s, b, "pb\n");
		sort_three(s);
		push(b, s, "pa\n");
		if (s->p[0] == 2)
		{
			ft_swaap(s->p, s->count, "sa\n");
			rolling(s->p, s->count, "ra\n");
			ft_swaap(s->p, s->count, "sa\n");
			rev_rolling(s->p, s->count);
		}
		else if (s->p[0] == 3)
			rolling(s->p, s->count, "ra\n");
		else if (s->p[0] == 1)
			ft_swaap(s->p, s->count, "sa\n");
	}
}
