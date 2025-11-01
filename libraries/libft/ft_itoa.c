/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:55:03 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/10/13 15:42:04 by rein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_reverse(char *str)
{
	char	*res;
	size_t	posfs;
	size_t	len;

	posfs = 0;
	len = ft_strlen((const char *)str);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (posfs < len)
	{
		res[posfs] = str[len - posfs - 1];
		posfs++;
	}
	res[posfs] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char		buffer[12];
	long int	nb;
	int			i;
	int			min;

	min = 0;
	i = 0;
	nb = n;
	if (nb == 0)
		buffer[i++] = '0';
	else if (n < 0)
	{
		min = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		buffer[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (min)
		buffer[i++] = '-';
	buffer[i] = '\0';
	return (ft_reverse(buffer));
}
