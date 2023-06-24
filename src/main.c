#include <system.h>
#include <punctual_body.h>

int main()
{
    // Creates a physics system
    System *s = system_new();

    // Creates a punctual body
    PunctualBody *pb1 = punctual_body_new();
    pb1->m = 5;
    // Set position to punctual body
    vector_set_x(pb1->position, 0);
    vector_set_y(pb1->position, 0);
    vector_set_z(pb1->position, 0);
    // Set velocity (vector and module) to punctual body
    Velocity *v1 = punctual_body_get_velocity(pb1);
    velocity_set_module(v1, 10);
    Vector *v1_vector = velocity_get_vector(v1);
    vector_set_x(v1_vector, 5);
    vector_set_y(v1_vector, 10);
    punctual_body_set_velocity(pb1, v1);
    // Add body to system
    system_add_body(s, pb1);

    // Run simulation for system s
    system_run(s);
}