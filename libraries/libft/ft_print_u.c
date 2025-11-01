/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_u.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/02 18:07:12 by rmengelb      #+#    #+#                 */
/*   Updated: 2024/11/03 12:26:01 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char	buffer[11];
	int		i;

	i = 10;
	buffer[i--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_strdup(&buffer[i + 1]));
}

int	ft_print_u(unsigned int u)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_utoa(u);
	if (temp == NULL)
		return (0);
	while (temp[i] != '\0')
	{
		write(1, &temp[i], 1);
		i++;
	}
	free(temp);
	return (i);
}
