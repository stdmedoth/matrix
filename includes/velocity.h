#ifndef __MATRIX_VELOCITY__
#define __MATRIX_VELOCITY__

#include <vector.h>

typedef struct _velocity
{
    Vector *position;
    double module;
} Velocity;

Velocity *velocity_new();

void velocity_set_position(Velocity *v, Vector *position);

void velocity_set_module(Velocity *v, double m);

void velocity_destroy(Velocity *v);

#endif