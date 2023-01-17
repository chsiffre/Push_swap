/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:18:10 by charles           #+#    #+#             */
/*   Updated: 2023/01/17 16:09:23 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_conv(long long int res)
{
	if (res > INT_MAX)
		return (res - LLONG_MAX - 1);
	else if (res < INT_MIN)
		return (res - LLONG_MIN);
	else
		return (res);
}

long long	ft_atoi(const char	*str)
{
	int				count;
	long long int	res;
	int				sign;

	count = 0;
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while ((*str == '-' || *str == '+') && ++count)
	{	
		if (*str == '-')
			sign *= -1;
		if (count > 1)
			return (2147364748);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((res * 10 + (*str - '0')) / 10 >= 2147364748)
			return (2147364748);
		res = (res * 10) + *str - '0';
		str++;
	}
	return ((int) ft_conv(res * sign));
}
