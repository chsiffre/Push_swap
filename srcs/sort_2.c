/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:56:29 by chsiffre          #+#    #+#             */
/*   Updated: 2023/01/26 14:59:22 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_stack(t_data *s)
{
	int	size;
	int	i;

	if (s->count == 2)
		rolling(s->p_a, s->count, "ra\n");
	else if (s->count == 3)
		sort_three(s);
	else if (s->count == 4)
		sort_four(s);
	size = s->count;
	i = -1;
	while (size > ++i)
	{
		if (s->p_a[0] < 2)
			pb(s);
		else
			rolling(s->p_a, s->count, "ra\n");
	}
	if (s->p_b[0] == 0)
		ft_swaap(s->p_b, s->size_pb, "sb\n");
	sort_three(s);
	while (s->size_pb)
		pa(s);
}

void	sort_three(t_data *s)
{
	if (s->p_a[0] > s->p_a[1] && s->p_a[1] < s->p_a[2]
		&& s->p_a[2] < s->p_a[0])
		return (rolling(s->p_a, s->count, "ra\n"));
	if (s->p_a[0] > s->p_a[1] && s->p_a[1] < s->p_a[2]
		&& s->p_a[2] > s->p_a[0])
		return (ft_swaap(s->p_a, s->count, "sa\n"));
	if (s->p_a[0] < s->p_a[1] && s->p_a[1] > s->p_a[2]
		&& s->p_a[2] < s->p_a[0])
		return (rev_rolling(s->p_a, s->count));
	if (s->p_a[0] < s->p_a[1] && s->p_a[1] > s->p_a[2]
		&& s->p_a[2] > s->p_a[0])
	{
		ft_swaap(s->p_a, s->count, "sa\n");
		return (rolling(s->p_a, s->count, "ra\n"));
	}
	if (s->p_a[0] > s->p_a[1] && s->p_a[1] > s->p_a[2])
	{
		ft_swaap(s->p_a, s->count, "sa\n");
		return (rev_rolling(s->p_a, s->count));
	}
}

void	sort_four(t_data *s)
{
	if (ft_is_sorted(s->p_a, s->count))
	{
		pb(s);
		sort_three(s);
		pa(s);
		if (s->p_a[0] == 2)
		{
			ft_swaap(s->p_a, s->count, "sa\n");
			rolling(s->p_a, s->count, "ra\n");
			ft_swaap(s->p_a, s->count, "sa\n");
			rev_rolling(s->p_a, s->count);
		}
		else if (s->p_a[0] == 3)
			rolling(s->p_a, s->count, "ra\n");
		else if (s->p_a[0] == 1)
			ft_swaap(s->p_a, s->count, "sa\n");
	}
}
