#include <stdlib.h>
#include <velocity.h>

Velocity *velocity_new()
{
    Velocity *v = malloc(sizeof(Velocity));

    Vector *vector = vector_new();
    velocity_set_position(v, vector);

    return v;
}

Vector *velocity_get_vector(Velocity *v)
{
    return v->vector;
}

void velocity_set_position(Velocity *v, Vector *vector)
{
    v->vector = vector;
    velocity_set_module(v, vector->module);
}

void velocity_set_module(Velocity *v, double m)
{
    v->vector->module = m;
}

double velocity_get_module(Velocity *v)
{
    return v->vector->module;
}

void velocity_destroy(Velocity *v)
{
    free(v);
}