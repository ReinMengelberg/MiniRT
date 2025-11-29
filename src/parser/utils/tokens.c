/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:41:33 by theyn             #+#    #+#             */
/*   Updated: 2025/11/28 15:42:39 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

int	token_count(char **tokens)
{
	int	count;

	if (!tokens)
		return (false);
	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

bool	check_token(char *token, char *expected)
{
	int	i;

	if (!token || !expected)
		return (false);
	i = 0;
	while (token[i] && expected[i])
	{
		if (token[i] != expected[i])
			return (false);
		i++;
	}
	return (token[i] == '\0' && expected[i] == '\0');
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static bool	check_float_char(char c, bool *has_dot, bool *has_digit)
{
	if (c == '.')
	{
		if (*has_dot)
			return (false);
		*has_dot = true;
	}
	else if (c >= '0' && c <= '9')
		*has_digit = true;
	else
		return (false);
	return (true);
}

bool	is_valid_float(char *str)
{
	int		i;
	bool	has_digit;
	bool	has_dot;

	if (!str || !*str)
		return (false);
	i = 0;
	has_digit = false;
	has_dot = false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!check_float_char(str[i], &has_dot, &has_digit))
			return (false);
		i++;
	}
	return (has_digit);
}
