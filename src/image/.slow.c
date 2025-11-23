/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   .slow.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 13:00:53 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 13:21:18 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void	render_pixel(t_image *img, t_composition *comp, int x, int y)
{
	t_color	color;
	t_ray	ray;

	ray = create_ray(comp->camera, comp->viewport, x, y);
	color = trace_ray(ray, comp);
	put_pixel(img, x, y, color);
}

static void	render_scene(t_image *img, t_composition *comp)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(img, comp, x, y);
			x++;
		}
		y++;
	}
}

t_image	*render_composition(void *mlx, t_composition *comp, t_image *ex_img)
{
	t_image	*img;

	img = init_image(mlx, ex_img);
	if (!img)
		return (NULL);
	render_scene(img, comp);
	return (img);
}

void	rerender_scene(t_mlx_data *data)
{
	data->img = render_composition(data->mlx, data->comp, data->img);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img_ptr, 0, 0);
}
