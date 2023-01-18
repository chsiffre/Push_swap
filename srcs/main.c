/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:38:23 by charles           #+#    #+#             */
/*   Updated: 2023/01/18 14:34:48 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*s;
	
	s = malloc(sizeof(t_data));
	if (ac < 2)
		return (write(2, "Error\n", 6));
	else
	{
		if (ft_count_args(av, s) == 0)
			return (free(s), write(2, "Error\n", 6), 0);
		else
			s->count = ft_count_args(av, s);
		s->p_a = malloc(ft_count_args(av, s) * sizeof(int));
		if (!s->p_a)
			return (free(s),0);
		ft_parsing(av, s);
	}
	if (!ft_is_sorted(s, s->count))
		return (free(s->p_a), free(s), ft_printf("deja trie"), 0);
	ft_position(s, s->count);
	ft_sort_big_stack(s, s->count);
	free(s->p_a);
	free(s);
	return (0);
}
