#ifndef __MATRIX_VECTOR__
#define __MATRIX_VECTOR__
typedef struct _vector
{
    int module;
    int x;
    int y;
    int z;
} Vector;

Vector *vector_new();
void vector_set_x(Vector *v, int x);

void vector_set_y(Vector *v, int y);

void vector_set_z(Vector *v, int z);

void vector_set_module(Vector *v, double m);

void vector_destroy(Vector *v);

#endif 