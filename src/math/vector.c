#include "renderclanker.h"

t_vector vadd(t_vector a, t_vector b) {
    t_vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

t_vector vsub(t_vector a, t_vector b) {
    t_vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

t_vector vscale(t_vector v, double scalar) {
    t_vector result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return result;
}

double vdot(t_vector a, t_vector b) {
    double result;
    result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    return result;
}

double vmagnitude(t_vector v) {
    double result;
    result = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return result;
}

t_vector vnormalize(t_vector v) {
    t_vector result;
    double mag = vmagnitude(v);
    result.x = v.x / mag;
    result.y = v.y / mag;
    result.z = v.z / mag;
    return result;
}

t_vector vcross(t_vector a, t_vector b) {
    t_vector result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

double vdistance(t_vector a, t_vector b) {
    t_vector diff;
    diff = vsub(b, a);
    return vmagnitude(diff);
}