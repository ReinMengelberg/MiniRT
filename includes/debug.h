/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 14:02:55 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 14:07:48 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DEBUG_H
# define PRINT_DEBUG_H

# include "renderclanker.h"

void	print_vector(const char *label, t_vector *v);
void	print_color(const char *label, t_color *c);
void	print_composition(t_composition *comp);
void	print_camera(t_camera *cam);
void	print_ambient(t_ambient *amb);
void	print_lights(t_light *lights);
void	print_objects(t_object *objects);
void	print_viewport(t_viewport *vp);

#endif