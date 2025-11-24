/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theyn <theyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:31:41 by theyn             #+#    #+#             */
/*   Updated: 2025/11/24 15:32:32 by theyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

void	free_sphere(t_sphere *sph)
{
	if (!sph)
		return ;
	if (sph->root)
		free(sph->root);
	if (sph->color)
		free(sph->color);
	free(sph);
}
