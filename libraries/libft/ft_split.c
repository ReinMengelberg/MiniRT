/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:28 by theyn             #+#    #+#             */
/*   Updated: 2025/06/20 11:18:34 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_substrings(const char *s, char c)
{
	size_t	count;
	int		in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
			in_substring = 0;
		s++;
	}
	return (count);
}

static char	*allocate_substring(const char *start, size_t length)
{
	char	*substring;
	size_t	i;

	substring = (char *)malloc((length + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < length)
	{
		substring[i] = start[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

static int	extract_substrings(char const *s, char c, char **result)
{
	size_t		i;
	const char	*substr_start;
	size_t		substr_length;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		substr_start = s;
		substr_length = 0;
		while (*s && *s != c)
		{
			substr_length++;
			s++;
		}
		if (substr_length > 0)
		{
			result[i] = allocate_substring(substr_start, substr_length);
			if (!result[i++])
				return (0);
		}
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	substr_count;
	size_t	j;
	char	**result;

	if (!s)
		return (NULL);
	substr_count = count_substrings(s, c);
	result = (char **)malloc((substr_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!extract_substrings(s, c, result))
	{
		j = 0;
		while (result[j])
			free (result[j++]);
		free (result);
		return (NULL);
	}
	return (result);
}
