/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:54 by apavel            #+#    #+#             */
/*   Updated: 2020/01/18 11:56:00 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static size_t	ft_count_digits(long n)
{
	size_t	digits;
	long	num;

	num = (n < 0) ? -n : n;
	digits = (n < 0) ? 2 : 1;
	while (num > 9)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

static void		ft_alloc_nums(char *str, long num, size_t div, int digits)
{
	int	i;

	i = (num < 0) ? 1 : 0;
	if (num < 0)
	{
		i = 1;
		num = num * -1;
		str[0] = '-';
		div /= 10;
	}
	else
		i = 0;
	while (i < digits)
	{
		str[i] = (num / div) + '0';
		num = num % div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		digits;
	size_t	div;
	long	num;

	num = n;
	digits = ft_count_digits(num);
	if (!(str = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	div = 1;
	i = -1;
	while (++i < digits - 1)
		div *= 10;
	ft_alloc_nums(str, num, div, digits);
	return (str);
}
