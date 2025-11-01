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

int	ft_which_print(char specifier, va_list args)
{
	int	pc;

	if (specifier == 'c')
		pc = ft_print_c(va_arg(args, int));
	else if (specifier == 's')
		pc = ft_print_s(va_arg(args, char *));
	else if (specifier == 'p')
		pc = ft_print_p(va_arg(args, void *));
	else if (specifier == 'd')
		pc = ft_print_d(va_arg(args, int));
	else if (specifier == 'i')
		pc = ft_print_i(va_arg(args, int));
	else if (specifier == 'u')
		pc = ft_print_u(va_arg(args, unsigned int));
	else if (specifier == 'x')
		pc = ft_print_x(va_arg(args, unsigned int));
	else if (specifier == 'X')
		pc = ft_print_xupper(va_arg(args, unsigned int));
	else if (specifier == '%')
		pc = ft_print_procent();
	else
		pc = 0;
	return (pc);
}
