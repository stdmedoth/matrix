#ifndef __MATRIX_SYSTEM__
#define __MATRIX_SYSTEM__
#include <energy.h>
typedef struct  _system
{
    MechanicalEnergy me;
    void *punctual_bodies;
} System;

#endif