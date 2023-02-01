/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:00:41 by charles           #+#    #+#             */
/*   Updated: 2023/02/01 14:41:40 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data *from, t_data *to, char *str)
{
	ssize_t	i;
	int		tmp;

	if (from->count <= 0)
		return ;
	ft_putstr(str);
	i = -1;
	tmp = from->p[0];
	from->count--;
	while (++i < from->count)
		from->p[i] = from->p[i + 1];
	to->count++;
	i = to->count;
	while (i > 0)
	{
		to->p[i] = to->p[i - 1];
		i--;
	}
	to->p[0] = tmp;
}

void	ft_swaap(int *tab, ssize_t count, char *str)
{
	int	tmp;

	ft_putstr(str);
	if (count > 1)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}

void	rev_rolling(int *tab, int count)
{
	int	tmp;
	int	i;

	ft_putstr("rra\n");
	i = count;
	tmp = tab[0];
	while (--i)
		tab[i] = tab[i - 1];
	tab[i] = tmp;
}

void	rolling(int *tab, ssize_t count, char *str)
{
	int		tmp;
	ssize_t	i;

	i = 0;
	ft_putstr(str);
	tmp = tab[0];
	while (i < count - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = tmp;
}
