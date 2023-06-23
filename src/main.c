#include <punctual_body.h>

int main()
{
    PunctualBody *pb = punctual_body_new();
    Velocity *v = velocity_new();
    velocity_set_module(v, 10);
    punctual_body_set_velocity(pb, v);
}