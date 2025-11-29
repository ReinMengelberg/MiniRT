/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 17:58:09 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 14:27:57 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_which_dprint(int fd, char specifier, va_list args)
{
	int	pc;

	if (specifier == 'c')
		pc = ft_dprint_c(fd, va_arg(args, int));
	else if (specifier == 's')
		pc = ft_dprint_s(fd, va_arg(args, char *));
	else if (specifier == 'p')
		pc = ft_dprint_p(fd, va_arg(args, void *));
	else if (specifier == 'd')
		pc = ft_dprint_d(fd, va_arg(args, int));
	else if (specifier == 'i')
		pc = ft_dprint_i(fd, va_arg(args, int));
	else if (specifier == 'u')
		pc = ft_dprint_u(fd, va_arg(args, unsigned int));
	else if (specifier == 'x')
		pc = ft_dprint_x(fd, va_arg(args, unsigned int));
	else if (specifier == 'X')
		pc = ft_dprint_xupper(fd, va_arg(args, unsigned int));
	else if (specifier == '%')
		pc = ft_dprint_procent(fd);
	else
		pc = 0;
	return (pc);
}

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
			pc += ft_which_dprint(1, format[++i], args);
		i++;
	}
	return (pc);
}

int	ft_dprintf(int fd, const char *format, ...)
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
			write(fd, &format[i], 1);
			pc++;
		}
		else
			pc += ft_which_dprint(fd, format[++i], args);
		i++;
	}
	return (pc);
}
