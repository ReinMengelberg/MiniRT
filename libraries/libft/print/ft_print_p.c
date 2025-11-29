/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 15:08:26 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 14:18:10 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprint_p(int fd, void *p)
{
	unsigned long	address;
	const char		*hex_digits;
	char			temp[19];
	int				i;

	hex_digits = "0123456789abcdef";
	i = 0;
	address = (unsigned long)p;
	if (p == NULL)
		return (ft_dprint_s(fd, "(nil)"));
	if (address == 0)
		temp[i++] = '0';
	while (address > 0)
	{
		temp[i++] = hex_digits[address % 16];
		address /= 16;
	}
	temp[i++] = 'x';
	temp[i++] = '0';
	temp[i] = '\0';
	return (ft_dprint_rev(fd, temp));
}
