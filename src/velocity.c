#include <stdlib.h>
#include <velocity.h>

Velocity *velocity_new()
{
    Velocity *v = malloc(sizeof(Velocity));
    
    Vector *vector = vector_new();
    v->vector = vector;

    return v;
}

Vector *velocity_get_vector(Velocity *v)
{
    return v->vector;
}

void velocity_set_position(Velocity *v, Vector *vector)
{
    v->vector = vector;
}

void velocity_set_module(Velocity *v, double m)
{
    v->module = m;
}

double velocity_get_module(Velocity *v)
{
    return v->module;
}

void velocity_destroy(Velocity *v)
{
    free(v);
}