#ifndef IMAGE_H
#define IMAGE_H

#include "renderclanker.h"
#include "vector.h"

typedef struct s_image {
	void    *img_ptr;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}   t_image;

typedef struct s_hit
{
	t_vector	*loc;		 // The 3D point where ray hit the object
	t_vector	*normal;     // Surface normal at hit point (for lighting)
	double	t;           // Distance along ray to hit point
	t_otype	type;
	void	*object;     // Pointer to the object that was hit
}   t_hit;


typedef struct s_ray {
	t_vector root;
	t_vector direction;
} t_ray;

typedef struct s_mlx_data {
	void		*mlx;
	void		*win;
	t_composition	*comp;
	t_image		*img;
}	t_mlx_data;

typedef struct s_thread_data{
	t_image		*img;
	t_composition	*comp;
	int			start_y;
	int			end_y;
}	t_thread_data;

#endif