/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:03:34 by theyn             #+#    #+#             */
/*   Updated: 2024/10/19 14:32:49 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negative;
	int	digit;

	i = 0;
	negative = 1;
	digit = 0;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = 10 * digit + (nptr[i] - '0');
		i++;
	}
	return (digit * negative);
}
