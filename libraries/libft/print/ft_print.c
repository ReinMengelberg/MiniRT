/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_which_print.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 13:09:08 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:26:46 by rmengelb      ########   odam.nl         */
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
