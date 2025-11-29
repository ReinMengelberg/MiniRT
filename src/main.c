/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/20 16:13:58 by theyn         #+#    #+#                 */
/*   Updated: 2025/11/29 16:29:58 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

#define KEY_ESC 65307

static void	cleanup_and_exit(t_mlx_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img->img_ptr);
		free(data->img);
	}
	mlx_destroy_window(data->mlx, data->win);
	if (data->comp)
		free_composition(data->comp);
	exit(0);
}

int	handle_keypress(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_ESC)
		cleanup_and_exit(data);
	else
	{
		handle_rotation_keys(keycode, data);
		handle_movement_keys(keycode, data);
	}
	return (0);
}

int	handle_close(t_mlx_data *data)
{
	cleanup_and_exit(data);
	return (0);
}

static int	init_mlx(t_mlx_data *data, t_composition *comp)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_dprintf(2, "Error: Failed to init MLX\n"), 1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "RenderClanker");
	if (!data->win)
		return (ft_dprintf(2, "Error: Failed to create window\n"), 1);
	data->comp = comp;
	data->img = NULL;
	return (0);
}

int	main(int ac, char **av)
{
	t_composition	*comp;
	t_mlx_data		data;

	if (validate_args(ac, av))
		return (1);
	comp = load_scene(av[1]);
	if (!comp)
		return (1);
	print_composition(comp);
	if (init_mlx(&data, comp))
		return (1);
	data.img = render_composition(data.mlx, comp, data.img);
	mlx_put_image_to_window(data.mlx, data.win, data.img->img_ptr, 0, 0);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_key_hook(data.win, handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}
