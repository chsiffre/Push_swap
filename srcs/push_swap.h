/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:59:15 by charles           #+#    #+#             */
/*   Updated: 2023/01/14 18:55:01 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_WAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct  s_data
{
    int *tab;
    int  count;
    size_t  i;
    size_t  x;
    
    
}t_data;

int main(int ac, char **av);
int free_tab(char **strs);
int ft_parsing(char **av, t_data *s);
int arg_space(char *av);
int	ft_check(int *tab, size_t count);
int ft_count_args(char **av, t_data *s);

#endif 