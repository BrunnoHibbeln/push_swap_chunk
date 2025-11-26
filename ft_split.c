/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:52:19 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/11/04 15:04:47 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	alloc(char **sv, int pos, size_t buffer)
{
	int	i;

	i = 0;
	sv[pos] = (char *)malloc(buffer);
	if (!sv[pos])
	{
		while (i < pos)
			free(sv[i++]);
		free(sv);
		return (0);
	}
	return (1);
}

static char	*cpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((src[i]) && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	fill(char **sv, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while ((*s == c) && (*s))
			s++;
		while ((*s != c) && (*s))
		{
			len++;
			s++;
		}
		if (len)
		{
			if (!alloc(sv, i, (len + 1)))
				return (0);
			cpy(sv[i], (s - len), (len + 1));
			i++;
		}
	}
	return (1);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	int		inside_word;

	words = 0;
	while (*s)
	{
		inside_word = 0;
		while ((*s == c) && (*s))
			s++;
		while ((*s != c) && (*s))
		{
			if (!inside_word)
			{
				words++;
				inside_word = 1;
			}
			s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**sv;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	sv = (char **)malloc(sizeof(char *) * (words + 1));
	if (!sv)
		return (NULL);
	if (!fill(sv, s, c))
		return (NULL);
	sv[words] = NULL;
	return (sv);
}
