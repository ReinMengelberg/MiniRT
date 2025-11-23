/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   composition.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 14:06:10 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 14:12:56 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	print_composition(t_composition *comp)
{
	if (!comp)
	{
		printf("Composition is NULL\n");
		return ;
	}
	printf("\n");
	printf("╔════════════════════════════════════════╗\n");
	printf("║       SCENE COMPOSITION SUMMARY        ║\n");
	printf("╚════════════════════════════════════════╝\n");
	print_camera(comp->camera);
	print_ambient(comp->ambient);
	print_lights(comp->lights);
	print_objects(comp->objects);
	print_viewport(comp->viewport);
	printf("\n");
}
