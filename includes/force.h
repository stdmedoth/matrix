#ifndef __MATRIX_FORCE__
#define __MATRIX_FORCE__

#include <vector.h>
#include <system.h>

typedef struct _force
{
    Vector v;
    System s; // mass center
} Force;

#endif