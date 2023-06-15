#ifndef __MATRIX_SYSTEM__
#define __MATRIX_SYSTEM__

#include <punctual_body.h>
#include <force.h>

typedef struct  _system
{
    PunctualBody *mcs; // mass centers
    PunctualBody *cm;  // mass center
    Force *forces; // internal forces
} System;

#endif