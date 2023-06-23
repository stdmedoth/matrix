#include <stdlib.h>
#include <velocity.h>

Velocity *velocity_new()
{
    Velocity *v = malloc(sizeof(Velocity));
    
    Vector *position = vector_new();
    v->position = position;

    return v;
}

void velocity_set_position(Velocity *v, Vector *position)
{
    v->position = position;
}

void velocity_set_module(Velocity *v, double m)
{
    v->module = m;
}

void velocity_destroy(Velocity *v)
{
    free(v);
}