/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:38:23 by charles           #+#    #+#             */
/*   Updated: 2023/02/01 14:45:22 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*s;

	s = malloc(sizeof(t_data));
	if (ac < 2)
		return (ft_exit(s));
	else
	{
		if (ft_count_args(av, s) == 0)
			return (ft_exit(s));
		else
			s->count = ft_count_args(av, s);
		s->tab = malloc(ft_count_args(av, s) * sizeof(int));
		if (!s->tab)
			return (free(s), 0);
		if (ft_parsing(av, s) == 1)
			return (0);
	}
	main_2(s);
}

int	main_2(t_data *s)
{
	t_data	*b;

	if (!ft_is_sorted(s->tab, s->count))
		return (ft_exit(s));
	b = ft_init(s);
	ft_position(s);
	if (s->count > 5)
		ft_sort_big_stack(s, b);
	else
		ft_sort_small_stack(s, b);
	ft_free_struct(s, b);
	return (0);
}

t_data	*ft_init(t_data *s)
{
	t_data	*b;

	b = malloc(sizeof(t_data));
	if (!b)
		return (NULL);
	b->count = 0;
	s->p = ft_calloc((s->count + 1), sizeof(int));
	if (!s->p)
		return (NULL);
	b->p = ft_calloc((s->count + 1), sizeof(int));
	if (!b->p)
		return (NULL);
	return (b);
}

int	ft_free_struct(t_data *s, t_data *b)
{
	if (b)
	{
		free(b->p);
		free(b);
	}
	free(s->p);
	free(s->tab);
	free(s);
	return (0);
}

int	ft_exit(t_data *s)
{
	free(s->tab);
	free(s);
	write(1, "Error\n", 6);
	return (1);
}
