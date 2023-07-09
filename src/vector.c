#include <stdlib.h>
#include <math.h>
#include <matrix.h>
#include <vector.h>

Vector *vector_new()
{
    Vector *v = malloc(sizeof(Vector));
    vector_set_x(v, 0);
    vector_set_y(v, 0);
    vector_set_z(v, 0);

    return v;
}

double vector_get_x(Vector *v)
{
    return v->x;
}

double vector_get_y(Vector *v)
{
    return v->y;
}

double vector_get_z(Vector *v)
{
    return v->z;
}

void vector_set_x(Vector *v, double x)
{
    v->x = x;
    double m = vector_get_module(v);
    vector_set_module(v, m);
}

void vector_set_y(Vector *v, double y)
{
    v->y = y;
    double m = vector_get_module(v);
    vector_set_module(v, m);
}

void vector_set_z(Vector *v, double z)
{
    v->z = z;
    double m = vector_get_module(v);
    vector_set_module(v, m);
}

double vector_get_module(Vector *v)
{
    return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}

void vector_set_module(Vector *v, double m)
{
    v->module = m;
}

int vector_component_compair(Vector *v1, Vector *v2)
{
    int is_x_equivalent = (v1->x == v2->x);
    int is_y_equivalent = (v1->y == v2->y);
    int is_z_equivalent = (v1->z == v2->z);

    if (is_x_equivalent && is_y_equivalent && is_z_equivalent)
        return TRUE;

    return FALSE;
}

void vector_destroy(Vector *v)
{
    free(v);
}