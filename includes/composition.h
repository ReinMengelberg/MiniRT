#ifndef COMPOSITION_H
#define COMPOSITION_H

typedef struct composition {
	camera  camera;
	ambient ambient;
	object  *objects;
	light   *lights;
} composition;

typedef struct camera {
	vector	root;
	vector	direction;
	int		fov;
} camera;

typedef struct ambient {
	float	intensity;
	color	color;
} ambient;

typedef struct light {
	light	*next;
	light	*prev;
	vector	root;
	float	brightness;
	color	color;
} light;

typedef struct object {
	object	*next;
	object	*prev;
	otype	type;
	void	*data;
} object;

typedef enum otype{
	SPHERE,
	CYLINDER,
	PLANE
} otype;

typedef struct sphere {
	vector	root;
	double	radius;
	color	color;
} sphere;

typedef struct cylinder {
	vector	root;
	vector	direction;
	double	radius;
	double	height;
	color	color;
} cylinder;

typedef struct plane {
	vector	root;
	vector	direction;
	color	color;
} plane;

typedef struct vector {
	double	x;
	double	y;
	double	z;
} vector;

typedef struct color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
} color;

#endif