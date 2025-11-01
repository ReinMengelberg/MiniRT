#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector {
	double	x;
	double	y;
	double	z;
} vector;

vector vadd(vector a, vector b);
vector vsub(vector a, vector b);
vector vscale(vector v, double scalar);
double vdot(vector a, vector b);
double vmagnitude(vector v);
vector vnormalize(vector v);
vector vcross(vector a, vector b);
double vdistance(vector a, vector b);

#endif