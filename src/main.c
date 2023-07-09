#include <system.h>
#include <punctual_body.h>

int main()
{

    // Creates a physics system
    System *s = system_new();

    // Creates a punctual body
    PunctualBody *pb1 = punctual_body_new();
    pb1->m = 1;
    // Set position to punctual body
    vector_set_x(pb1->position, 0);
    vector_set_y(pb1->position, 0);
    vector_set_z(pb1->position, 0);
    // Set velocity (vector and module) to punctual body
    Velocity *v1 = punctual_body_get_velocity(pb1);
    Vector *v1_vector = velocity_get_vector(v1);
    vector_set_x(v1_vector, 3);
    vector_set_y(v1_vector, 0);
    vector_set_z(v1_vector, 0);
    punctual_body_set_velocity(pb1, v1);
    // Add body to system
    system_add_body(s, pb1);

    // Creates a punctual body
    PunctualBody *pb2 = punctual_body_new();
    pb2->m = 3;
    // Set position to punctual body
    vector_set_x(pb2->position, 10);
    vector_set_y(pb2->position, 0);
    vector_set_z(pb2->position, 0);
    // Set velocity (vector and module) to punctual body
    Velocity *v2 = punctual_body_get_velocity(pb2);
    Vector *v2_vector = velocity_get_vector(v2);
    vector_set_x(v2_vector, -1);
    vector_set_y(v2_vector, 0);
    vector_set_z(v2_vector, 0);
    punctual_body_set_velocity(pb2, v2);
    // Add body to system
    system_add_body(s, pb2);

    // Run simulation for system s
    system_run(s);
}