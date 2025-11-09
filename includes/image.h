#ifndef IMAGE_H
#define IMAGE_H

typedef struct s_img {
	void    *img_ptr;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}   t_image;

typedef struct s_ray {
	vector root;
	vector direction;
} t_ray;

#endif