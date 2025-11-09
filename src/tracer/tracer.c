/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:45:02 by rmengelb          #+#    #+#             */
/*   Updated: 2025/11/09 13:18:49 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

color	return_grey()
{
	color	gray;

	gray.r = 128;
	gray.g = 128;
	gray.b = 128;
	
	return (gray);
}

color	return_red()
{
	color	gray;

	gray.r = 255;
	gray.g = 0;
	gray.b = 0;
	
	return (gray);
}

color	return_green()
{
	color	gray;

	gray.r = 0;
	gray.g = 255;
	gray.b = 0;
	
	return (gray);
}

color	return_blue()
{
	color	gray;

	gray.r = 0;
	gray.g = 0;
	gray.b = 0;
	
	return (gray);
}

color	trace_ray(t_ray ray, composition *comp)
{
	t_hit	hit;
	bool	found;
	
	found = find_intersect(ray, comp, &hit);
	if (!found)
		return (return_grey());
	
	if (hit.type == SPHERE)
		return (*((sphere *)hit.object)->color);
	else if (hit.type == PLANE)
		return (*((plane *)hit.object)->color);
	else if (hit.type == CYLINDER)
		return (*((cylinder *)hit.object)->color);
	return (return_grey());
}