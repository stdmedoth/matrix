#ifndef __MATRIX_VELOCITY__
#define __MATRIX_VELOCITY__

#include <vector.h>

typedef struct _velocity
{
    Vector *vector;
} Velocity;

Velocity *velocity_new();

Vector *velocity_get_vector(Velocity *v);

double velocity_get_module(Velocity *v);

void velocity_set_position(Velocity *v, Vector *position);

void velocity_set_module(Velocity *v, double m);

void velocity_destroy(Velocity *v);

#endif