/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 14:05:15 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 14:05:26 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	print_vector(const char *label, t_vector *v)
{
	if (!v)
	{
		printf("%s: NULL\n", label);
		return ;
	}
	printf("%s: (%.6f, %.6f, %.6f)\n", label, v->x, v->y, v->z);
}

void	print_color(const char *label, t_color *c)
{
	if (!c)
	{
		printf("%s: NULL\n", label);
		return ;
	}
	printf("%s: RGB(%d, %d, %d)\n", label, c->r, c->g, c->b);
}