/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:59:15 by charles           #+#    #+#             */
/*   Updated: 2023/01/20 14:12:58 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	int		*p_a;
	int		*p_b;
	int		*tab;
	int		size_pb;
	int		count;
	size_t	i;
	size_t	x;
}t_data;

int	main(int ac, char **av);
int	free_tab(char **strs);
int	ft_parsing(char **av, t_data *s);
int	arg_space(char *av);
int	ft_check(t_data *s, ssize_t count);
int	ft_count_args(char **av, t_data *s);
int	ft_is_sorted(t_data *s, size_t count);
void ft_position(t_data *s, ssize_t count);
void	ft_sort_big_stack(t_data *s);
void	pa(t_data *s);
void    pb(t_data *s);
void    ft_swaap(int *tab, ssize_t count, char *str);
void    rolling(int *tab, ssize_t count, char *str);


#endif
