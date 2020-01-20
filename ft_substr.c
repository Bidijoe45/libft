/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:26:30 by apavel            #+#    #+#             */
/*   Updated: 2020/01/16 11:29:29 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned char	*u_s;
	unsigned char	*str;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	u_s = (unsigned char *)s;
	i = 0;
	while (u_s[start + i] != '\0' && i < len)
	{
		str[i] = u_s[start + i];
		i++;
	}
	str[i] = '\0';
	return (char *)str;
}
