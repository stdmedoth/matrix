#include <stdlib.h>
#include <vector.h>

Vector *vector_new()
{
    Vector *v = malloc(sizeof(Vector));

    return v;
}

void vector_set_x(Vector *v, int x)
{
    v->x = x;
}

void vector_set_y(Vector *v, int y)
{
    v->y = y;
}

void vector_set_z(Vector *v, int z)
{
    v->z = z;
}

void vector_set_module(Vector *v, double m)
{
    v->module = m;
}

void vector_destroy(Vector *v)
{
    free(v);
}