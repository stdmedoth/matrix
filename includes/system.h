#ifndef __MATRIX_SYSTEM__
#define __MATRIX_SYSTEM__

#include <time.h>
#include <energy.h>
typedef struct  _system
{
    MechanicalEnergy me;
    time_t *time;
    void *punctual_bodies;
} System;

#endif