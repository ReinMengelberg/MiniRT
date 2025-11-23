/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   composition.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: theyn <theyn@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/09 13:20:14 by theyn         #+#    #+#                 */
/*   Updated: 2025/11/23 12:32:56 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderclanker.h"

static void print_vector(const char *label, t_vector *v)
{
    if (!v)
    {
        printf("%s: NULL\n", label);
        return;
    }
    printf("%s: (%.6f, %.6f, %.6f)\n", label, v->x, v->y, v->z);  // Changed to %.6f
}

static void print_color(const char *label, t_color *c)
{
    if (!c)
    {
        printf("%s: NULL\n", label);
        return;
    }
    printf("%s: RGB(%d, %d, %d)\n", label, c->r, c->g, c->b);
}

static void print_camera(t_camera *cam)
{
    if (!cam)
    {
        printf("Camera: NULL\n");
        return;
    }
    printf("\n=== CAMERA ===\n");
    print_vector("  Position", cam->root);
    print_vector("  Direction", cam->direction);
    printf("  FOV: %d\n", cam->fov);
    printf("  Focal length: %.2f\n", cam->focal);
}

static void print_ambient(t_ambient *amb)
{
    if (!amb)
    {
        printf("\nAmbient: NULL\n");
        return;
    }
    printf("\n=== AMBIENT LIGHT ===\n");
    printf("  Intensity: %.2f\n", amb->intensity);
    print_color("  Color", amb->color);
}

static void print_lights(t_light *lights)
{
    int count = 0;
    
    printf("\n=== LIGHTS ===\n");
    if (!lights)
    {
        printf("  No lights\n");
        return;
    }
    
    t_light *curr = lights;
    while (curr)
    {
        printf("  Light #%d:\n", ++count);
        print_vector("    Position", curr->root);
        printf("    Brightness: %.2f\n", curr->brightness);
        print_color("    Color", curr->color);
        curr = curr->next;
    }
}

static void print_sphere(t_sphere *sp)
{
    print_vector("    Center", sp->root);
    printf("    Radius: %.2f\n", sp->radius);
    print_color("    Color", sp->color);
}

static void print_cylinder(t_cylinder *cyl)
{
    print_vector("    Center", cyl->root);
    print_vector("    Direction", cyl->direction);
    printf("    Radius: %.2f\n", cyl->radius);
    printf("    Height: %.2f\n", cyl->height);
    print_color("    Color", cyl->color);
}

static void print_plane(t_plane *pl)
{
    print_vector("    Point", pl->root);
    print_vector("    Normal", pl->direction);
    print_color("    Color", pl->color);
}

static void print_objects(t_object *objects)
{
    int count = 0;
    
    printf("\n=== OBJECTS ===\n");
    if (!objects)
    {
        printf("  No objects\n");
        return;
    }
    
    t_object *curr = objects;
    while (curr)
    {
        printf("  Object #%d:\n", ++count);
        
        if (curr->type == SPHERE)
        {
            printf("    Type: SPHERE\n");
            if (curr->data)
                print_sphere((t_sphere *)curr->data);
        }
        else if (curr->type == CYLINDER)
        {
            printf("    Type: CYLINDER\n");
            if (curr->data)
                print_cylinder((t_cylinder *)curr->data);
        }
        else if (curr->type == PLANE)
        {
            printf("    Type: PLANE\n");
            if (curr->data)
                print_plane((t_plane *)curr->data);
        }
        
        curr = curr->next;
    }
}

static void print_viewport(t_viewport *vp)
{
    if (!vp)
    {
        printf("\nViewport: NULL\n");
        return;
    }
    printf("\n=== VIEWPORT ===\n");
    printf("  Dimensions: %.2f x %.2f\n", vp->width, vp->height);
    print_vector("  Horizontal vector", &vp->hvec);
    print_vector("  Vertical vector", &vp->vvec);
    print_vector("  H pixel delta", &vp->hpdelta);
    print_vector("  V pixel delta", &vp->vpdelta);
    print_vector("  Top-left pixel", &vp->ptl);
    print_vector("  Pixel (0,0)", &vp->p00);
}

void print_composition(t_composition *comp)
{
    if (!comp)
    {
        printf("Composition is NULL\n");
        return;
    }
    
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║       SCENE COMPOSITION SUMMARY        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    print_camera(comp->camera);
    print_ambient(comp->ambient);
    print_lights(comp->lights);
    print_objects(comp->objects);
    print_viewport(comp->viewport);
    
    printf("\n");
}