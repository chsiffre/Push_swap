/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:59:12 by charles           #+#    #+#             */
/*   Updated: 2023/01/17 16:11:24 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_tab(char **strs)
{
	size_t	i;

	i = -1;
	if (!strs)
		return (0);
	if (strs[0] || strs)
	{
		while (strs[++i])
			free(strs[i]);
		free(strs);
	}
	return (0);
}

int	arg_space(char *av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]) && av[i] != ' ' && av[i] != '-')
			return (2);
		if (av[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_args(char **av, t_data *s)
{	
	s->count = 0;
	s->i = 0;
	while (av[++s->i])
	{
		if (arg_space(av[s->i]) == 1)
		{
			s->x = 0;
			while (av[s->i][s->x])
			{
				while (av[s->i][s->x] == ' ' && av[s->i][s->x])
					s->x++;
				while (av[s->i][s->x] != ' ' && av[s->i][s->x])
				{
					s->x++;
					if (av[s->i][s->x] == ' ' || !av[s->i][s->x])
						s->count++;
				}
			}
		}
		else if (arg_space(av[s->i]) == 2)
			return (0);
		else
			s->count++;
	}
	return (s->count);
}

int	ft_check(t_data *s, ssize_t count)
{
	ssize_t	i;
	ssize_t	y;

	i = 0;
	while (i < count)
	{
		y = i + 1;
		while (y < count)
		{
			if (s->tab[i] == s->tab[y])
				return (write(2, "Error\n", 6), 1);
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_parsing(char **av, t_data *s)
{
	ssize_t	i;
	ssize_t	y;
	ssize_t	x;
	char	**strs;

	i = 0;
	x = 0;
	while (i < ft_count_args(av, s))
	{
		y = -1;
		strs = ft_split(av[++x], ' ');
		while (strs[++y])
		{
			if (ft_atoi(strs[y]) == 2147364748)
				return (free_tab(strs), write(2, "Error\n", 6), 1);
			else
				s->tab[i++] = ft_atoi(strs[y]);
		}
		free_tab(strs);
	}
	ft_check(s, ft_count_args(av, s));
	return (0);
}
