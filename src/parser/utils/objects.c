#include "renderclanker.h"

vector	*fill_vector(char *token)
{
	char	**xyz;
	vector	*vec;

	xyz = ft_split(token, ',');
	if (!xyz || token_count(xyz) != 3)
	{
		free_tokens(xyz);
		return NULL;
	}
	vec = malloc(sizeof(vector));
	if (!vec) {
		free_tokens(xyz);
		return NULL;
	}
	vec->x = ft_atof(xyz[0]);
	vec->y = ft_atof(xyz[1]);
	vec->z = ft_atof(xyz[2]);
	free_tokens(xyz);
	if (!vec->x || !vec->y || !vec->z) {
		free(vec);
		return (perror("Error: Failed to parse root vector"), NULL);
	}
	return vec;
}

vector	*fill_direction(char *token) {
	char	**xyz;
	vector	*vec;

	xyz = ft_split(token, ',');
	if (!xyz || token_count(xyz) != 3) {
		free_tokens(xyz);
		return NULL;
	}
	vec = malloc(sizeof(vector));
	if (!vec) {
		free_tokens(xyz);
		return NULL;
	}
	vec->x = ft_atof(xyz[0]);
	vec->y = ft_atof(xyz[1]);
	vec->z = ft_atof(xyz[2]);
	free_tokens(xyz);
	if (!vec->x || !vec->y || !vec->z) {
		free(vec);
		return (perror("Error: Failed to parse direction vector"), NULL);
	}
	if (vec->x > 1 || vec->x < -1 ||vec->y > 1 || vec->y < -1 ||vec->z > 1 || vec->z < -1) {
		free(vec);
		return (perror("Error: direction vector values should be in range [-1.0,1.0]"), NULL);
	}
	return vec;
}

color *fill_color(char *token) {
    char    **rgb;
    color   *col;

    rgb = ft_split(token, ',');
    if (!rgb || token_count(rgb) != 3) {
        free_tokens(rgb);
        return NULL;
    }
    col = malloc(sizeof(color));
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
        return (perror("Error: color values should be in range [0,255]"), NULL);
    }
    return col;
}

void add_object_to_list(composition *comp, object *new_obj) {
	object *current;

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

void free_object_data(object *obj) {
	if (!obj || !obj->data)
		return;

	if (obj->type == SPHERE) {
		sphere *s = (sphere *)obj->data;
		if (s->root) free(s->root);
		if (s->color) free(s->color);
		free(s);
	} else if (obj->type == CYLINDER) {
		cylinder *c = (cylinder *)obj->data;
		if (c->root) free(c->root);
		if (c->direction) free(c->direction);
		if (c->color) free(c->color);
		free(c);
	} else if (obj->type == PLANE) {
		plane *p = (plane *)obj->data;
		if (p->root) free(p->root);
		if (p->direction) free(p->direction);
		if (p->color) free(p->color);
		free(p);
	}
}

void free_all_objects(object *objects) {
	object *current;
	object *next;
	
	current = objects;
	while (current) {
		next = current->next;
		free_object_data(current);
		free(current);
		current = next;
	}
}
