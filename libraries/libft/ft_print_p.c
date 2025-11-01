/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 15:08:26 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:25:48 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(void *p)
{
	unsigned long	address;
	const char		*hex_digits;
	char			temp[19];
	int				i;

	hex_digits = "0123456789abcdef";
	i = 0;
	address = (unsigned long)p;
	if (p == NULL)
		return (ft_print_s("(nil)"));
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
	return (ft_rev_and_write(temp));
}
