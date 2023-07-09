#ifndef __MATRIX_COLLISION__
#define __MATRIX_COLLISION__

#include <system.h>
#include <punctual_body.h>

int collision_check_collisions(System *s);

void collision_elastic_collision(PunctualBody *pb1, PunctualBody *pb2);

#endif