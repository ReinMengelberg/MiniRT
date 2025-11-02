#include "renderclanker.h"

bool add_cylinder(composition *comp, char *line) {
    char    **tokens;
    object  *new_obj;
    object  *current;
    
    tokens = ft_split(line, ' ');
    if (token_count(tokens) != 6 || !check_token(tokens[0], "cy")) {
        free_array(tokens);
        return (perror("Incorrect cylinder definition in .rt file"), false);
    }
    
    // Create new object node
    new_obj = malloc(sizeof(object));
    if (!new_obj) {
        free_array(tokens);
        return (perror("Memory allocation failed"), false);
    }
    
    new_obj->type = CYLINDER;
    new_obj->data = parse_cylinder(tokens);
    new_obj->next = NULL;
    new_obj->prev = NULL;
    
    // Check if parse_cylinder failed
    if (!new_obj->data) {
        free(new_obj);
        free_array(tokens);
        return (perror("Failed to parse cylinder"), false);
    }
    

	add_object_to_list(comp, new_obj);
    free_array(tokens);
    return (true);
}

camera *parse_camera(char **tokens) {
	camera *cam;

	cam = malloc(sizeof(caminder));
	if (!cam) {
		return (perror("Failed to allocate memory for a camera"), NULL);
	}

	cam->root = fill_vector(tokens[1]);
	cam->direction = fill_direction(tokens[2]);
	cam->fov = ft_atoi(tokens[3]);
	free_array(tokens);

	if (!cam->root || !cam->direction || !cam->radius || !cam->height || !cam->color) {
		free_object(cam);
		return (perror("Incorrect camera definition in .rt file"), NULL);
	}	

	return cam;
}

void free_camera(camera *cam) {
	if (cam->root) free(cam->root);
	if (cam->direction) free(cam->direction);
	free(cam);
}