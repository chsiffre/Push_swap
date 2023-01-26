/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:00:41 by charles           #+#    #+#             */
/*   Updated: 2023/01/26 17:11:58 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *s)
{
	int		tmp;
	int		*temp;
	ssize_t	i;

	i = -1;
	if (s->size_pb <= 0)
		return ;
	write(1, "pa\n", 3);
	tmp = s->p_b[0];
	temp = s->p_b;
	s->p_b = malloc(s->size_pb-- * sizeof(int));
	if (!s->p_b)
		return ;
	i = -1;
	while (++i < s->size_pb)
		s->p_b[i] = temp[i + 1];
	temp = s->p_a;
	s->p_a = malloc(s->count++ * sizeof(int));
	if (!s->p_b)
		return ;
	s->p_a[0] = tmp;
	i = 0;
	while (++i < s->count)
		s->p_a[i] = temp[i - 1];
	//free(temp);
}

void	pb(t_data *s)
{
	int		tmp;
	int		*temp;
	ssize_t	i;

	i = -1;
	if (s->count <= 0)
		return ;
	write(1, "pb\n", 3);
	tmp = s->p_a[0];
	temp = s->p_a;
	s->p_a = malloc(s->count-- * sizeof(int));
	if (!s->p_a)
		return ;
	while (++i < s->count)
		s->p_a[i] = temp[i + 1];
	temp = s->p_b;
	s->p_b = malloc(s->size_pb++ * sizeof(int));
	if (!s->p_b)
		return ;
	s->p_b[0] = tmp;
	i = 0;
	while (++i < s->size_pb)
		s->p_b[i] = temp[i - 1];
	//free(temp);
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
