/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:53:13 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/14 16:53:15 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_sp(char *str, int *pi)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	*pi = i;
	return (sign);
}

long	ft_atoi(const char	*str)
{
	int		i;
	int		s;
	long	r;
	long	prev_r;

	i = 0;
	r = 0;
	s = skip_sp((char *)str, &i);
	while (((char *)str)[i] >= '0' && ((char *)str)[i] <= '9')
	{
		prev_r = r;
		r = r * 10 + (((char *)str)[i++] - 48);
		if ((r / 10) != prev_r)
			Fatals(1);
	}
	return (r * s);
}
