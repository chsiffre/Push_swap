/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:00:41 by charles           #+#    #+#             */
/*   Updated: 2023/01/29 18:48:06 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data *from, t_data *to, char *str)
{
	ssize_t	i;
	int tmp;
	
	if (from->count <= 0)
		return ;
	ft_putstr(str);
	i = -1;
	tmp = from->p[0];
	from->count--;
	while (++i < from->count)
		from->p[i] = from->p[i + 1];
	i = 0;
	to->count++;
	while (++i < to->count)
		to->p[i] = to->p[i- 1];
	to->p[0] = tmp;
	i = -1;
	while (++i < to->count)
		ft_printf("%d ", to->p[i]);
	i = -1;
	while (++i < from->count)
		ft_printf("%d,", from->p[i]);
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
