#include "renderclanker.h"

typedef struct compostion {
    camera  camera;
    ambient ambient;
    object  *objects;
    light   *lights;
} composition;

typedef struct camera {

} camera;

typedef struct ambient {

} ambient;

typedef struct object {
    object  *next;
    object  *prev;
    otype   type;
    void    *data; // Points to sphere, plane or cylinder
} object;

typedef struct light {
    object  *next;
    object  *prev;

};

typedef enum otype{
    SPHERE,
    CYLINDER,
    PLANE
} otype;

typedef struct sphere {
    
} sphere;

typedef struct cylinder {
    
} cylinder;

typedef struct plane {
    
} sphere;

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

