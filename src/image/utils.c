/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmengelb <rmengelb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/23 13:09:49 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/23 13:13:29 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

int	color_to_hex(t_color c)
{
	int	result;

	result = (c.r << 16) | (c.g << 8) | c.b;
	return (result);
}

void	put_pixel(t_image *img, int x, int y, t_color c)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color_to_hex(c);
}

t_image	*init_image(void *mlx, t_image *existing_img)
{
	t_image	*img;

	if (existing_img)
		return (existing_img);
	img = malloc(sizeof(t_image));
	if (!img)
		return (dprintf(2, "Failed to allocate memory for image"), NULL);
	img->img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}
