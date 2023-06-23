#ifndef __MATRIX_PUNTUAL_BODY__
#define __MATRIX_PUNTUAL_BODY__

#include <vector.h>
#include <system.h>
#include <pthread.h>
#include <velocity.h>

typedef struct _punctual_body
{
    System *system;
    Vector *position;
    double m;
    Velocity *v;

    pthread_t *pt;
    time_t time;
} PunctualBody;

PunctualBody *punctual_body_new();

void punctual_body_set_position(PunctualBody *pb, Vector *position);

void punctual_body_set_mass(PunctualBody *pb, double m);

void punctual_body_set_velocity(PunctualBody *pb, Velocity *v);

void punctual_body_time_init(PunctualBody *pb);

void *punctual_body_time_counter(void *pb);

void punctual_body_destroy(PunctualBody *pb);

#endif