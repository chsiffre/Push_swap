/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:38:23 by charles           #+#    #+#             */
/*   Updated: 2023/01/27 14:04:46 by charles          ###   ########.fr       */
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
	if (!ft_is_sorted(s->tab, s->count))
		return (ft_exit(s));
	ft_init(s);
	ft_position(s);
	if (s->count > 5)
		ft_sort_big_stack(s);
	else
		ft_sort_small_stack(s);
	free(s->tab);
	free(s->p_a);
	free(s->p_b);
	free(s);
	return (0);
}

void	ft_init(t_data *s)
{
	s->size_pb = 0;
	s->p_a = malloc(s->count * sizeof(int));
	s->p_b = malloc(s->count * sizeof(int));
}

int ft_exit(t_data *s)
{
	free(s->tab);
	free(s);
	write(1, "Error\n", 6);
	return (1);
}