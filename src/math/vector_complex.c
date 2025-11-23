/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 13:26:16 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 13:27:33 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

double	vmagnitude(t_vector v)
{
	double	result;

	result = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (result);
}

t_vector	vnormalize(t_vector v)
{
	t_vector	result;
	double		mag;

	mag = vmagnitude(v);
	result.x = v.x / mag;
	result.y = v.y / mag;
	result.z = v.z / mag;
	return (result);
}

t_vector	vcross(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

double	vdistance(t_vector a, t_vector b)
{
	t_vector	diff;

	diff = vsub(b, a);
	return (vmagnitude(diff));
}
