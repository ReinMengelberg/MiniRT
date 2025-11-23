/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 14:04:27 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 14:14:07 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void	print_sphere(t_sphere *sp)
{
	print_vector("    Center", sp->root);
	printf("    Radius: %.2f\n", sp->radius);
	print_color("    Color", sp->color);
}

static void	print_cylinder(t_cylinder *cyl)
{
	print_vector("    Center", cyl->root);
	print_vector("    Direction", cyl->direction);
	printf("    Radius: %.2f\n", cyl->radius);
	printf("    Height: %.2f\n", cyl->height);
	print_color("    Color", cyl->color);
}

static void	print_plane(t_plane *pl)
{
	print_vector("    Point", pl->root);
	print_vector("    Normal", pl->direction);
	print_color("    Color", pl->color);
}

static void	print_object_data(t_object *curr)
{
	if (curr->type == SPHERE && curr->data) {
		printf("    Type: SPHERE\n");
		print_sphere((t_sphere *)curr->data);
	}
	else if (curr->type == CYLINDER && curr->data) {
		printf("    Type: CYLINDER\n");
		print_cylinder((t_cylinder *)curr->data);
	}
	else if (curr->type == PLANE && curr->data) {
		printf("    Type: PLANE\n");
		print_plane((t_plane *)curr->data);
	}
}

void	print_objects(t_object *objects)
{
	int			count;
	t_object	*curr;

	count = 0;
	printf("\n=== OBJECTS ===\n");
	if (!objects)
	{
		printf("  No objects\n");
		return ;
	}
	curr = objects;
	while (curr)
	{
		printf("  Object #%d:\n", ++count);
		print_object_data(curr);
		curr = curr->next;
	}
}