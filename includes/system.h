#ifndef __MATRIX_SYSTEM__
#define __MATRIX_SYSTEM__

#include <time.h>
#include <energy.h>
typedef struct  _system
{
    MechanicalEnergy me;
    time_t *time;
    int pb_index;
    void **punctual_bodies;
} System;

System *system_new();

void system_run(System *s);
void system_add_body(System *s, void *pb);

void system_destroy(System *s);


#endif