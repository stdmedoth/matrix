#include <system.h>
#include <punctual_body.h>

int main()
{
    System *s = system_new();
    PunctualBody *pb1 = punctual_body_new();
    pb1->position->x = 0;
    pb1->position->y = 0;
    pb1->position->z = 0;
    Velocity *v1 = velocity_new();
    velocity_set_module(v1, 10);
    Vector *v1_vector = velocity_get_vector(v1);
    v1_vector->x = 5;
    v1_vector->y = 10;
    punctual_body_set_velocity(pb1, v1);
    system_add_body(s, pb1);

    PunctualBody *pb2 = punctual_body_new();
    pb2->position->x = 0;
    pb2->position->y = 0;
    pb2->position->z = 0;
    Velocity *v2 = velocity_new();
    velocity_set_module(v2, 10);
    punctual_body_set_velocity(pb2, v2);
    system_add_body(s, pb2);

    system_run(s);
}