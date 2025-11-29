/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 12:19:28 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/29 12:19:35 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

t_vector	vadd(t_vector a, t_vector b);
t_vector	vsub(t_vector a, t_vector b);
t_vector	vscale(t_vector v, double scalar);
double		vdot(t_vector a, t_vector b);
double		vmagnitude(t_vector v);
t_vector	vnormalize(t_vector v);
t_vector	vcross(t_vector a, t_vector b);
double		vdistance(t_vector a, t_vector b);

#endif