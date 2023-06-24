#include <stdio.h>
#include <stdlib.h>
#include <punctual_body.h>

PunctualBody *punctual_body_new()
{
    PunctualBody * pb = malloc(sizeof(PunctualBody));
    pb->m = 0;

    Vector *position = vector_new();
    pb->position = position;
    
    Velocity *v = velocity_new();
    pb->v = v;

    pb->me = energy_new();
    pb->me->kine.m = pb->m;
    pb->me->kine.v = v;

    return pb;
}

Velocity *punctual_body_get_velocity(PunctualBody *pb)
{
    return pb->v;
}

Vector *punctual_body_get_position(PunctualBody *pb)
{
    return pb->position;
}

MechanicalEnergy *punctual_body_get_energy(PunctualBody *pb)
{
    return pb->me;
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

