/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:00:41 by charles           #+#    #+#             */
/*   Updated: 2023/01/27 14:37:45 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *tab_to, int *tab_from, int size_to, int size_from)
{
	ssize_t	i;
	int tmp;
	
	if (size_to <= 0)
		return ;
	i = 0;
	tmp = tab_to[0];
	size_to--;
	while (++i < size_to)
		tab_to[i] = tab_to[i + 1];
	i = 0;
	size_from++;
	while (++i < size_from)
		tab_from[i] = tab_from[i- 1];
	tab_from[0] = tmp;
	i = -1;
	while (++i < size_to)
		ft_printf("%d ", tab_to[i]);
	i = -1;
	while (++i < size_from)
		ft_printf("%d,", tab_from[i]);
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
