#ifndef __MATRIX_SYSTEM__
#define __MATRIX_SYSTEM__

#include <punctual_body.h>

typedef struct  _system
{
    PunctualBody *mcs; // mass centers
    PunctualBody *cm;  // mass center
} System;

#endif