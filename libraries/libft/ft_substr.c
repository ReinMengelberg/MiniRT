/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:58:13 by theyn             #+#    #+#             */
/*   Updated: 2025/05/03 15:15:11 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	string_length;
	char	*sub;

	i = 0;
	string_length = 0;
	if (!s)
		return (NULL);
	string_length = ft_strlen(s);
	if (start >= string_length)
		return (ft_strdup(""));
	string_length -= start;
	if (string_length > len)
		string_length = len;
	sub = (char *)malloc((string_length + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < string_length)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
