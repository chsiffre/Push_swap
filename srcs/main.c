/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:38:23 by charles           #+#    #+#             */
/*   Updated: 2023/01/20 15:55:06 by hdupuy           ###   ########.fr       */
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
		s->tab = malloc(ft_count_args(av, s) * sizeof(int));
		if (!s->tab)
			return (free(s),0);
		ft_parsing(av, s);
	}
	if (!ft_is_sorted(s, s->count))
		return (free(s->tab), free(s), ft_printf("deja trie"), 0);
	ft_position(s, s->count);
    s->size_pb = 0;
	ft_sort_big_stack(s);
	free(s->tab);
	free(s);
	return (0);
}
