/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 17:14:24 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/10/13 17:07:25 by rein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntstr(char const *s, char c)
{
	size_t	i;
	size_t	len;
	int		flag;

	i = 0;
	len = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			len++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (len);
}

static char	**ft_free(char **res, size_t j)
{
	while (j > 0)
		free(res[--j]);
	free(res);
	return (NULL);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	amount;
	size_t	i;
	size_t	j;
	size_t	word_len;
	char	**res;

	i = 0;
	j = 0;
	amount = ft_cntstr(s, c);
	res = malloc(sizeof(char *) * (amount + 1));
	if (!res)
		return (NULL);
	while (j < amount)
	{
		while (s[i] == c)
			i++;
		word_len = ft_word_len(s + i, c);
		res[j] = ft_strndup(s + i, word_len);
		if (!res[j])
			return (ft_free(res, j));
		j++;
		i += word_len;
	}
	res[j] = NULL;
	return (res);
}
