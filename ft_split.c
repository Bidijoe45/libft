/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:18:07 by apavel            #+#    #+#             */
/*   Updated: 2020/01/21 18:14:44 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	if (s[0] != c)
		words++;
	else
		words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static size_t	ft_next_sep(const char *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start] != c && s[start] != '\0')
	{
		start++;
		i++;
	}
	return (i);
}

static void		ft_alloc_wrds(char **table, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		table[i] = ft_substr(s, j, ft_next_sep(s, j, c));
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	table[i] = NULL;
}

char			**ft_split(const char *s, char c)
{
	char	**table;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(table = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	if (s[0] == '\0')
	{
		table[0] = NULL;
		return (table);
	}
	ft_alloc_wrds(table, s, c, words);
	return (table);
}
