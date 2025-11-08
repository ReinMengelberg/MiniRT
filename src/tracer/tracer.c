#include "renderclanker.h"

color	return_grey()
{
	color	gray;

	gray.r = 128;
	gray.g = 128;
	gray.b = 128;
	
	return (gray);
}

double	intersect_sphere(t_ray ray, sphere *sp)
{

}

double	intersect_plane(t_ray ray, plane *pl)
{

}

double	intersect_cylinder(t_ray ray, cylinder *cyl)
{
	
}

color	calculate_lighting(t_ray ray, object *hit_obj, double closest_t, composition *comp)
{

}

color	trace_ray(t_ray ray, composition *comp)
{
	t_hit_info	hit;

	if (!find_closest_intersection(ray, comp, &hit))
		return (return_grey());
	return (calculate_lighting(ray, &hit, comp));
}

color	trace_ray(t_ray ray, composition *comp)
{
	double		closest_t;
	object		*hit_obj;

	closest_t = INFINITY;
	hit_obj = NULL;
	hit_obj = find_closest_intersection(ray, comp, &closest_t);
	if (hit_obj == NULL)
		return (return_grey());
	return (calculate_lighting(ray, hit_obj, closest_t, comp));
}

object	*find_closest_intersection(t_ray ray, composition *comp, double *t)
{
	object	*current;
	object	*closest;
	double	closest_t;
	double	temp_t;

	closest = NULL;
	closest_t = INFINITY;
	current = comp->objects;
	while (current)
	{
		if (current->type == SPHERE)
			temp_t = intersect_sphere(ray, (sphere *)current->data);
		else if (current->type == PLANE)
			temp_t = intersect_plane(ray, (plane *)current->data);
		else if (current->type == CYLINDER)
			temp_t = intersect_cylinder(ray, (cylinder *)current->data);
		if (temp_t > 0.001 && temp_t < *t)
		{
			*t = temp_t;
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

