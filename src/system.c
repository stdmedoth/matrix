#include <stdio.h>
#include <stdlib.h>
#include <system.h>
#include <vector.h>
#include <collision.h>
#include <matrix_time.h>
#include <punctual_body.h>

System *system_new()
{
    System *s = malloc(sizeof(System));
    s->pb_index = 0;
    s->punctual_bodies = malloc(sizeof(void *));

    return s;
}

void system_add_body(System *s, void *pb)
{
    // s->punctual_bodies[s->pb_index] = malloc(sizeof(pb));
    s->punctual_bodies[s->pb_index] = pb;
    s->pb_index++;
}

void system_destroy(System *s)
{
    free(s);
}

void system_run(System *s)
{
    int time = 0;
    while (1)
    {
        for (int i = 0; i < s->pb_index; i++)
        {
            PunctualBody *pb = s->punctual_bodies[i];

            Velocity *v = punctual_body_get_velocity(pb);
            double v_module = velocity_get_module(v);
            MechanicalEnergy *me = punctual_body_get_energy(pb);
            me->kine.m = pb->m;
            me->kine.v = v;

            if (v_module != 0)
            {

                Vector *position = punctual_body_get_position(pb);
                Vector *v_vector = velocity_get_vector(v);

                double new_x = vector_get_x(position) + (vector_get_x(v_vector) * MATRIX_SECOND / 50);
                double new_y = vector_get_y(position) + (vector_get_y(v_vector) * MATRIX_SECOND / 50);
                double new_z = vector_get_z(position) + (vector_get_z(v_vector) * MATRIX_SECOND / 50);
                char text[200];
                /*
                sprintf(text, "pb %d vector(%d,%d,%d) + vector(%d,%d,%d)\n",
                        i,
                        vector_get_x(position),
                        vector_get_y(position),
                        vector_get_z(position),
                        vector_get_x(v_vector),
                        vector_get_y(v_vector),
                        vector_get_z(v_vector));
                printf(text);
                */
                vector_set_x(position, new_x);
                vector_set_y(position, new_y);
                vector_set_z(position, new_z);
            }

            Vector *position = punctual_body_get_position(pb);
            char text[200];
            sprintf(text, "time: %d pb %d velocity %f position (%f,%f,%f)\n", time, i, v_module, vector_get_x(position), vector_get_y(position), vector_get_z(position));
            printf(text);

            sprintf(text, "time: %d pb %d kinect energy (%f)\n", time, i, energy_get_kinect_value(me));
            // printf(text);
            collision_check_collisions(s);
        }
        time++; // 1 milisecond
        if (time >= (MATRIX_SECOND))
        {
            break;
        }
    }
}