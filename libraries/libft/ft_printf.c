/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 17:58:09 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:26:15 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	size_t		i;
	va_list		args;
	long int	pc;

	i = 0;
	pc = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			pc++;
		}
		else
			pc += ft_which_print(format[++i], args);
		i++;
	}
	return (pc);
}
