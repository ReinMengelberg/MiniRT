#include "renderclanker.h"

bool	is_valid_int(char *str)
{
	int	i = 0;

	if (!str || !*str)
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

t_vector	*fill_vector(char *token)
{
    char	**xyz;
    t_vector	*vec;

    xyz = ft_split(token, ',');
    if (!xyz || token_count(xyz) != 3) {
        free_tokens(xyz);
        return NULL;
    }
    if (!is_valid_float(xyz[0]) || !is_valid_float(xyz[1]) || !is_valid_float(xyz[2])) {
        free_tokens(xyz);
        return (dprintf(2, "Error: Failed to parse vector from token %s\n", token), NULL);
    }
    vec = malloc(sizeof(t_vector));
    if (!vec) {
        free_tokens(xyz);
        return NULL;
    }
    vec->x = ft_atof(xyz[0]);
    vec->y = ft_atof(xyz[1]);
    vec->z = ft_atof(xyz[2]);
    free_tokens(xyz);
    return vec;
}

t_vector	*fill_direction(char *token) {
    char	**xyz;
    t_vector	*vec;

    xyz = ft_split(token, ',');
    if (!xyz || token_count(xyz) != 3) {
        free_tokens(xyz);
        return NULL;
    }
    if (!is_valid_float(xyz[0]) || !is_valid_float(xyz[1]) || !is_valid_float(xyz[2])) {
        free_tokens(xyz);
        return (dprintf(2, "Error: Failed to parse direction vector from token %s\n", token), NULL);
    }
    vec = malloc(sizeof(t_vector));
    if (!vec) {
        free_tokens(xyz);
        return NULL;
    }
    vec->x = ft_atof(xyz[0]);
    vec->y = ft_atof(xyz[1]);
    vec->z = ft_atof(xyz[2]);
    free_tokens(xyz);
    if (vec->x > 1 || vec->x < -1 ||vec->y > 1 || vec->y < -1 ||vec->z > 1 || vec->z < -1) {
        free(vec);
        return (dprintf(2, "Error: direction vector values should be in range [-1.0,1.0]\n"), NULL);
    }
    return vec;
}

t_color *fill_color(char *token) {
    char    **rgb;
    t_color   *col;

    rgb = ft_split(token, ',');
    if (!rgb || token_count(rgb) != 3) {
        free_tokens(rgb);
        return NULL;
    }
    col = malloc(sizeof(t_color));
    if (!col) {
        free_tokens(rgb);
        return NULL;
    }
    col->r = (unsigned char)ft_atoi(rgb[0]);
    col->g = (unsigned char)ft_atoi(rgb[1]);
    col->b = (unsigned char)ft_atoi(rgb[2]);
    free_tokens(rgb);
    if (col->r < 0 || col->r > 255 || col->g < 0 || col->g > 255 || col->b < 0 || col->b > 255) {
        free(col);
        return (dprintf(2, "Error: color values should be in range [0,255]\n"), NULL);
    }
    return col;
}

void add_object_to_list(t_composition *comp, t_object *new_obj) {
	t_object *current;

	if (!comp->objects) {
		// First object in the list
		comp->objects = new_obj;
	} else {
		// Find the last object and append
		current = comp->objects;
		while (current->next)
			current = current->next;
		current->next = new_obj;
		new_obj->prev = current;
	}
}

void free_object_data(t_object *obj) {
	if (!obj || !obj->data)
		return;

	if (obj->type == SPHERE) {
		t_sphere *s = (t_sphere *)obj->data;
		if (s->root) free(s->root);
		if (s->color) free(s->color);
		free(s);
	} else if (obj->type == CYLINDER) {
		t_cylinder *c = (t_cylinder *)obj->data;
		if (c->root) free(c->root);
		if (c->direction) free(c->direction);
		if (c->color) free(c->color);
		free(c);
	} else if (obj->type == PLANE) {
		t_plane *p = (t_plane *)obj->data;
		if (p->root) free(p->root);
		if (p->direction) free(p->direction);
		if (p->color) free(p->color);
		free(p);
	}
}

void free_all_objects(t_object *objects) {
	t_object *current;
	t_object *next;
	
	current = objects;
	while (current) {
		next = current->next;
		free_object_data(current);
		free(current);
		current = next;
	}
}
