/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:21:50 by rmengelb      #+#    #+#                 */
/*   Updated: 2025/11/09 15:12:47 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

#define KEY_LEFT	65363
#define KEY_RIGHT	65361
#define KEY_UP		65362
#define KEY_DOWN	65364
#define KEY_W		119
#define KEY_D		100
#define KEY_S		115
#define KEY_A		97

#define ROTATE_STEP	0.1
#define MOVE_STEP	1

int	handle_keypress(int keycode, mlx_data *data) {
	printf("GETTING KEYPRESS %d\n", keycode);
	if (keycode == KEY_ESC) {
		if (data->img)
			mlx_destroy_image(data->mlx, data->img->img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		free_composition(data->comp);
		exit(0);
	}
	else if (keycode == KEY_LEFT) {
		rotate_camera_y(data->comp, ROTATE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_RIGHT) {
		rotate_camera_y(data->comp, -ROTATE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_UP) {
		rotate_camera_x(data->comp, ROTATE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_DOWN) {
		rotate_camera_x(data->comp, -ROTATE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_W) {
		move_camera_forward(data->comp, MOVE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_S) {
		move_camera_forward(data->comp, -MOVE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_A) {
		move_camera_strafe(data->comp, -MOVE_STEP);
		rerender_scene(data);
	}
	else if (keycode == KEY_D) {
		move_camera_strafe(data->comp, MOVE_STEP);
		rerender_scene(data);
	}
	
	return (0);
}

int	handle_close(mlx_data *data) {
	mlx_destroy_window(data->mlx, data->win);
	free_composition(data->comp);
	exit(0);
	return (0);
}

int	main(int ac, char **av) {
	int			fd;
	composition	*comp;
	mlx_data	data;
	
	if (ac != 2)
		return (dprintf(2, "Error:Usage: ./miniRT <scene.rt>\n"), 1);
	if (!ft_strnstr(av[1], ".rt", ft_strlen(av[1])))
		return (dprintf(2, "Error: File must have .rt extension\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (dprintf(2, "Error: Can't open file\n"), 1);
	comp = create_composition(fd);
	close(fd);
	if (!comp)
		return (dprintf(2, "Error: Failed to parse scene\n"), 1);
	print_composition(comp);
	
	data.mlx = mlx_init();
	if (!data.mlx)
		return (dprintf(2, "Error: Failed to init MLX\n"), 1);
	
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MiniRT");
	if (!data.win)
		return (dprintf(2, "Error: Failed to create window\n"), 1);
	
	data.comp = comp;
	data.img = NULL;  // Initialize to NULL for first render
	data.img = render_composition(data.mlx, comp, data.img);
	mlx_put_image_to_window(data.mlx, data.win, data.img->img_ptr, 0, 0);
	
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_key_hook(data.win, handle_keypress, &data);
	
	mlx_loop(data.mlx);
	
	return (0);
}