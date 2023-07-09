#ifndef __MATRIX_VECTOR__
#define __MATRIX_VECTOR__
typedef struct _vector
{
    double module;
    double x;
    double y;
    double z;
} Vector;

Vector *vector_new();

double vector_get_x(Vector *v);

double vector_get_y(Vector *v);

double vector_get_z(Vector *v);

void vector_set_x(Vector *v, double x);

void vector_set_y(Vector *v, double y);

void vector_set_z(Vector *v, double z);

double vector_get_module(Vector *v);
void vector_set_module(Vector *v, double m);

int vector_component_compair(Vector *v1, Vector *v2);

void vector_destroy(Vector *v);

#endif