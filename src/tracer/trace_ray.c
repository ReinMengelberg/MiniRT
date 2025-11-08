#include "renderclanker.h"

color	trace_ray(t_ray ray, composition *comp)
{
	double		closest_t;
	object		*hit_obj;

	closest_t = INFINITY;
	hit_obj = NULL;
	hit_obj = find_closest_intersection(ray, comp, &closest_t);
	if (hit_obj == NULL)
		return (comp->bg_color); //////////Add to composition struct, or pre-define in composition.h
	return (calculate_lighting(ray, hit_obj, closest_t, comp));
}

object	*find_closest_intersection(t_ray ray, composition *comp, double *t)
{
	object	*current;
	object	*closest;
	double	temp_t;

	closest = NULL;
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

double	intersect_sphere(t_ray ray, sphere *sp)
{

}