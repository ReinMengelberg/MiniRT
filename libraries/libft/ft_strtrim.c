/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:11:15 by theyn             #+#    #+#             */
/*   Updated: 2024/10/16 15:20:17 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			start;
	size_t			end_position;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end_position = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end_position > start && ft_strrchr(set, s1[end_position - 1]))
		end_position--;
	if (start >= end_position)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end_position - start));
}
