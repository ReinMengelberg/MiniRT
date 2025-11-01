#include "renderclanker.h"

vector vadd(vector a, vector b) {
    vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

vector vsub(vector a, vector b) {
    vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

vector vscale(vector v, double scalar) {
    vector result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return result;
}

double vdot(vector a, vector b) {
    double result;
    result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    return result;
}

double vmagnitude(vector v) {
    double result;
    result = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return result;
}

vector vnormalize(vector v) {
    vector result;
    double mag = vmagnitude(v);
    result.x = v.x / mag;
    result.y = v.y / mag;
    result.z = v.z / mag;
    return result;
}

vector vcross(vector a, vector b) {
    vector result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

double vdistance(vector a, vector b) {
    vector diff;
    diff = vsub(b, a);
    return vmagnitude(diff);
}