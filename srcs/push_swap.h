/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:59:15 by charles           #+#    #+#             */
/*   Updated: 2022/12/19 11:56:01 by charles          ###   ########.fr       */
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
    
}t_data;


int free_tab(char **strs);
int ft_parsing(int count, char **av, t_data *s);

#endif 