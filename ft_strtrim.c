/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:25:29 by apavel            #+#    #+#             */
/*   Updated: 2020/01/16 11:26:08 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	str_len;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	str_len = ft_strlen(s1);
	j = str_len - 1;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[j]) != 0)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
