/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:38:23 by charles           #+#    #+#             */
/*   Updated: 2023/01/14 18:55:14 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_data *s;
    
    s = malloc(sizeof(t_data));
    if (ac < 2)
        return (ft_printf("Error\n"));
    else
    {
        if (ft_count_args(av, s) == 1)
            return (ft_printf("Invalid Argument"), 0);
        ft_parsing(av, s);
    }
    return (0);
}