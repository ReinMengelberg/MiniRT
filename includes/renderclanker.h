#ifndef RENDERCLANKER_H
#   define RENDERCLANKER_H

#include <pthread.h>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "fcntl.h"
#include "libft.h"
#include <mlx.h>

// STRUCTS
#include "vector.h"
#include "composition.h"
#include "image.h"

#define WIDTH 800
#define HEIGHT 600

#define NUM_THREADS 8

#ifndef M_PI
#   define M_PI 3.14159265358979323846
#endif

/**
 * PARSING
 */

composition	*create_composition(int fd);
bool		add_ambient(composition *comp, char *line);
bool		add_camera(composition *comp, char *line);
bool		add_light(composition *comp, char *line);
bool		add_cylinder(composition *comp, char *line);
bool		add_plane(composition *comp, char *line);
bool		add_sphere(composition *comp, char *line);

t_viewport	*calculate_viewport(camera *cam, int width, int height);
vector		*fill_vector(char *token);
vector		*fill_direction(char *token);
color		*fill_color(char *token);
void		add_object_to_list(composition *comp, object *new_obj);
void		free_object_data(object *obj);
void		free_all_objects(object *objects);
void		free_all_lights(light *lights);
void		free_ambient(ambient *ambient);
void		free_camera(camera *camera);
void		free_composition(composition *comp);
void	    free_viewport(t_viewport *vp);

bool		is_valid_int(char *str);
int			token_count(char **tokens);
bool		check_token(char *token, char *expected);
void		free_tokens(char **tokens);
bool		is_valid_float(char *str);
double		ft_atod(char *str);
float		ft_atof(char *str);

/**
 * DEBUG
 */

void print_composition(composition *comp);

/**
 * IMAGE
 */

t_image *render_composition(void *mlx, composition *comp, t_image *existing_img);


/**
 * MOVEMENT
 */
void	rotate_camera_y(composition *comp, float angle);
void	rotate_camera_x(composition *comp, float angle);
void	move_camera_forward(composition *comp, float distance);
void	move_camera_strafe(composition *comp, float distance);
void	rerender_scene(mlx_data *data);

/**
 * CREATOR
 */

t_ray	create_ray(camera *cam, t_viewport *vp, int x, int y);

/**
 * TRACER
 */

color	trace_ray(t_ray ray, composition *comp);
bool	find_intersect(t_ray ray, composition *comp, t_hit *hit);
bool	intersect_cylinder(t_ray ray, cylinder *cyl, t_hit *hit);
bool	intersect_sphere(t_ray ray, sphere *s, t_hit *hit);
bool	intersect_plane(t_ray ray, plane *p, t_hit *hit);
bool	try_intersection(t_ray ray, double t, cylinder *cyl, vector axis, t_hit *hit);

/**
 * MATH
 */

vector vadd(vector a, vector b);
vector vsub(vector a, vector b);
vector vscale(vector v, double scalar);
double vdot(vector a, vector b);
double vmagnitude(vector v);
vector vnormalize(vector v);
vector vcross(vector a, vector b);
double vdistance(vector a, vector b);


#endif