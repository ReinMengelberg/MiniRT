#include "renderclanker.h"

void add_object_to_list(composition *comp, object *new_obj)
{
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
