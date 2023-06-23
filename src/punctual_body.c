#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <punctual_body.h>

PunctualBody *punctual_body_new()
{
    PunctualBody * pb = malloc(sizeof(PunctualBody));
    
    Vector *position = vector_new();
    pb->position = position;
    
    Velocity *v = velocity_new();
    pb->v = v;

    punctual_body_time_init(pb);
    pb->time = 0;

    return pb;
}

void punctual_body_set_position(PunctualBody *pb, Vector *position)
{
    pb->position = position;
}

void punctual_body_set_mass(PunctualBody *pb, double m)
{
    pb->m = m;
}

void punctual_body_set_velocity(PunctualBody *pb, Velocity *v)
{
    pb->v = v;
}

void punctual_body_destroy(PunctualBody *pb)
{
    free(pb);
}

void punctual_body_time_init(PunctualBody *pb)
{
}


void *punctual_body_time_counter(void *pb)
{
}