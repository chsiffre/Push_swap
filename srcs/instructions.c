/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:00:41 by charles           #+#    #+#             */
/*   Updated: 2023/01/18 18:12:34 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_data *s)
{
    int tmp;
    int *temp;
    ssize_t  i;

    i = -1;
    if (s->size_pb < 0)
        return ;
    write(1,"Pa\n", 3);
    tmp = s->p_b[0];
    temp = s->p_b;
    s->p_b = malloc(--s->size_pb * sizeof(int));
    if (!s->p_b)
        return ;
    while (++i < s->size_pb)
        s->p_b[i] = temp[i + 1];
    free(temp);
    temp = s->p_a;
    s->p_a = malloc(++s->count * sizeof(int));
    if (!s->p_b)
        return ;
    s->p_a[0] = tmp;
    i = -1;
    while (++i < s->count)
        s->p_a[i + 1] = temp[i];
    free(temp); 
}

void    pb(t_data *s)
{
    int tmp;
    int *temp;
    ssize_t  i;

    i = -1;
    if (s->count < 0)
        return ;
    write(1,"Pb\n", 3);
    tmp = s->p_a[0];
    temp = s->p_a;
    s->p_a = malloc(--s->count * sizeof(int));
    if (!s->p_a)
        return ;
    while (++i < s->count)
        s->p_a[i] = temp[i + 1];
    free(temp);
    temp = s->p_b;
    s->p_b = malloc(++s->size_pb * sizeof(int));
    if (!s->p_a)
        return ;
    s->p_b[0] = tmp;
    i = -1;
    while (++i < s->count)
        s->p_b[i + 1] = temp[i];
    free(temp); 
}

void    ft_swaap(int *tab, ssize_t count, char *str)
{
    int tmp;
    
    ft_putstr(str);
    if (count > 1)
    {
        tmp = tab[0];
        tab[0] = tab[1];
        tab[1] = tmp;
    }
}

void    rolling(int *tab, ssize_t count, char *str)
{
    int tmp;
    ssize_t  i;

    i = -1;
    if (!tab[0])
        return ;
    ft_putstr(str);
    tmp = tab[count - 1];
    tab[0] = tmp;
    while (++i < count)
        tab[i + 1] = tab[i];
}
