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

#define NUM_THREADS 16

#ifndef M_PI
#   define M_PI 3.14159265358979323846
#endif

/**
 * PARSING
 */

t_composition	*create_composition(int fd);
bool		add_ambient(t_composition *comp, char *line);
bool		add_camera(t_composition *comp, char *line);
bool		add_light(t_composition *comp, char *line);
bool		add_cylinder(t_composition *comp, char *line);
bool		add_plane(t_composition *comp, char *line);
bool		add_sphere(t_composition *comp, char *line);

t_viewport	*calculate_viewport(t_camera *cam, int width, int height);
t_vector		*fill_vector(char *token);
t_vector		*fill_direction(char *token);
t_color		*fill_color(char *token);
void		add_object_to_list(t_composition *comp, t_object *new_obj);
void		free_object_data(t_object *obj);
void		free_all_objects(t_object *objects);
void		free_all_lights(t_light *lights);
void		free_ambient(t_ambient *ambient);
void		free_camera(t_camera *camera);
void		free_composition(t_composition *comp);
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

void print_composition(t_composition *comp);

/**
 * IMAGE
 */

t_image *render_composition(void *mlx, t_composition *comp, t_image *existing_img);


/**
 * MOVEMENT
 */
void	rotate_camera_y(t_composition *comp, float angle);
void	rotate_camera_x(t_composition *comp, float angle);
void	move_camera_forward(t_composition *comp, float distance);
void	move_camera_strafe(t_composition *comp, float distance);
void	rerender_scene(t_mlx_data *data);

/**
 * CREATOR
 */

t_ray	create_ray(t_camera *cam, t_viewport *vp, int x, int y);

/**
 * TRACER
 */

t_color	trace_ray(t_ray ray, t_composition *comp);
bool	find_intersect(t_ray ray, t_composition *comp, t_hit *hit);
bool	intersect_cylinder(t_ray ray, t_cylinder *cyl, t_hit *hit);
bool	intersect_sphere(t_ray ray, t_sphere *s, t_hit *hit);
bool	intersect_plane(t_ray ray, t_plane *p, t_hit *hit);
bool	try_intersection(t_ray ray, double t, t_cylinder *cyl, t_vector axis, t_hit *hit);
bool	is_in_shadow(t_vector *hit_point, t_vector *light_pos, t_composition *comp);
void	free_hit_data(t_hit *hit);
void	clamp_color_values(t_color *final_color);
t_color	init_ambient_color(t_color *obj_color, double ambient_intensity);
t_color	*get_object_color(t_hit *hit);
t_color	return_grey(void);
t_color	calculate_lighting(t_hit *hit, t_composition *comp);

/**
 * MATH
 */

t_vector vadd(t_vector a, t_vector b);
t_vector vsub(t_vector a, t_vector b);
t_vector vscale(t_vector v, double scalar);
double vdot(t_vector a, t_vector b);
double vmagnitude(t_vector v);
t_vector vnormalize(t_vector v);
t_vector vcross(t_vector a, t_vector b);
double vdistance(t_vector a, t_vector b);


#endif