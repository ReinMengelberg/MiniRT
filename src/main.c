#include "renderclanker.h"
#include <mlx.h>

#define WIDTH 800
#define HEIGHT 600

#define KEY_ESC 65307

typedef struct mlx_data {
	void		*mlx;
	void		*win;
	composition	*comp;

}	mlx_data;

int	handle_keypress(int keycode, mlx_data *data) {
	if (keycode == KEY_ESC) {
		mlx_destroy_window(data->mlx, data->win);
		free_composition(data->comp);
		exit(0);
	}
	return (0);
}

int	handle_close(mlx_data *data) {
	mlx_destroy_window(data->mlx, data->win);
	free_composition(data->comp);
	exit(0);
	return (0);
}

bool	validate_composition(composition *comp) {
	if (!comp->camera)
		return (dprintf(2, "Error: No camera defined in .rt file\n"), false);
	if (!comp->ambient)
		return (dprintf(2, "Error: No ambient defined in .rt file\n"), false);
	if (!comp->lights)
		return (dprintf(2, "Error: No lights defined in .rt file\n"), false);
	return (true);
}


int	main(int ac, char **av) {
	int			fd;
	composition	*comp;
	// mlx_data	data;

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
	if (!validate_composition(comp)) {
		free_composition(comp); ///////////////////MAKE THIS FUNCTION
		return (1);
	}

	// data.comp = comp;
	// data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "miniRT");
	// if (!data.win) {
	// 	free_composition(comp);
	// 	return (dprintf(2, "Error: Failed to create window\n"), 1);
	// }
	// mlx_key_hook(data.win, handle_keypress, &data);
	// mlx_hook(data.win, 17, 0, handle_close, &data);
	// mlx_loop(data.mlx);
	free_composition(comp);
	return (0);
}