#include <stdlib.h>
#include <vector.h>

Vector *vector_new()
{
    Vector *v = malloc(sizeof(Vector));
    vector_set_x(v, 0);
    vector_set_y(v, 0);
    vector_set_z(v, 0);

    return v;
}

int vector_get_x(Vector *v)
{
    return v->x;
}

int vector_get_y(Vector *v)
{
    return v->y;
}

int vector_get_z(Vector *v)
{
    return v->z;
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