/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:07:34 by apavel            #+#    #+#             */
/*   Updated: 2020/01/21 12:43:01 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*hstck;

	hstck = (char *)haystack;
	if (!needle[0])
		return (char *)haystack;
	needle_len = ft_strlen(needle);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (!ft_strncmp(&haystack[i], needle, needle_len)
				&& (i + needle_len) <= len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
