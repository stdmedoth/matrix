#include <stdlib.h>
#include <punctual_body.h>

PunctualBody *punctual_body_new()
{
    PunctualBody * pb = malloc(sizeof(PunctualBody*));
    
    Vector *position = malloc(sizeof(Vector*));
    pb->position = position;
    
    Velocity *v = malloc(sizeof(Velocity *));
    pb->v = v;

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