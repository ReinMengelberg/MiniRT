/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:55:27 by theyn             #+#    #+#             */
/*   Updated: 2025/11/20 16:17:31 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void	setup_cylinder_projections(t_ray ray, cylinder *cyl,\
	vector axis, t_cylinder_calc *calc)
{
	vector	oc;

	oc = vsub(ray.root, *cyl->root);
	calc->dir_proj = vsub(ray.direction,
			vscale(axis, vdot(ray.direction, axis)));
	calc->oc_proj = vsub(oc, vscale(axis, vdot(oc, axis)));
}

static void	calculate_quadratic(t_cylinder_calc *calc, double radius)
{
	calc->a = vdot(calc->dir_proj, calc->dir_proj);
	calc->b = 2.0 * vdot(calc->oc_proj, calc->dir_proj);
	calc->c = vdot(calc->oc_proj, calc->oc_proj) - (radius * radius);
}

static double	get_discriminant(t_cylinder_calc *calc)
{
	return (calc->b * calc->b - 4 * calc->a * calc->c);
}

static void	calculate_t_values(t_cylinder_calc *calc,\
	double discriminant, double *t1, double *t2)
{
	*t1 = (-calc->b - sqrt(discriminant)) / (2.0 * calc->a);
	*t2 = (-calc->b + sqrt(discriminant)) / (2.0 * calc->a);
}

bool	intersect_cylinder(t_ray ray, cylinder *cyl, t_hit *hit)
{
	t_cylinder_calc	calc;
	vector			axis;
	double			discriminant;
	double			t1;
	double			t2;

	axis = vnormalize(*cyl->direction);
	setup_cylinder_projections(ray, cyl, axis, &calc);
	calculate_quadratic(&calc, cyl->radius);
	discriminant = get_discriminant(&calc);
	if (discriminant < 0)
		return (false);
	calculate_t_values(&calc, discriminant, &t1, &t2);
	if (try_intersection(ray, t1, cyl, axis, hit))
		return (true);
	if (try_intersection(ray, t2, cyl, axis, hit))
		return (true);
	return (false);
}
