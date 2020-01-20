/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:06:29 by apavel            #+#    #+#             */
/*   Updated: 2020/01/14 13:42:06 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i] != '\0')
	{
		ptr[j] = s2[i];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
