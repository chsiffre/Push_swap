/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:59:12 by charles           #+#    #+#             */
/*   Updated: 2022/12/19 11:55:45 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int free_tab(char **strs)
{
    size_t  i;

    i = -1;
    if (strs[i] || strs)
    {
        while (strs[++i])
            free(strs[i]);
        free(strs);
    }
    return (0);
}

int ft_parsing(int count, char **av, t_data *s)
{
    ssize_t i;
    size_t y;
    i = 1;

    s->tab = malloc(count * sizeof(int));
    if (!s->tab)
        return 0;
    while (av[i])
    {
        y = 0;
        s->tab[i] = ft_atoi(av[i]);
        if (s->tab[i] < INT_MIN || s->tab[i] > INT_MAX)
            return (free_tab(av));
        while (s->tab[y] <= i - 1)
        {
            if (s->tab[y] == s->tab[i])
                return (ft_printf("Error"));
            y++;
        }
        ft_printf("%d ", s->tab[i]);
        i++;
    }
    //return (free_tab(av));
    return 0;
}



int main(int ac, char **av)
{
    int count;
    t_data *s;
    
    s = malloc(sizeof(t_data));
    count = ac - 1;
    if (ac < 2)
        return (ft_printf("Error\n"));
    else
    {
        ft_parsing(count, av, s);
    }
    return (0);
}