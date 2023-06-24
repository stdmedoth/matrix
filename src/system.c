#include <stdio.h>
#include <stdlib.h>
#include <system.h>
#include <vector.h>
#include <punctual_body.h>

System *system_new()
{
    System *s = malloc(sizeof(System));
    s->pb_index = 0;
    s->punctual_bodies = malloc(sizeof(void*));

    return s;
}

void system_add_body(System *s, void *pb)
{
    //s->punctual_bodies[s->pb_index] = malloc(sizeof(pb));
    s->punctual_bodies[s->pb_index] = pb;
    s->pb_index++;
}

void system_destroy(System *s)
{
    free(s);
}

void system_run(System *s)
{
    while(1){
        for(int i=0; i < s->pb_index; i++){
                PunctualBody *pb = s->punctual_bodies[i];
                Velocity *v = punctual_body_get_velocity(pb);
                if(v->module != 0){
                    
                    Vector *position = punctual_body_get_position(pb);
                    Vector *v_vector = velocity_get_vector(v);
                    
                    int new_x = vector_get_x(position) + vector_get_x(v_vector);
                    int new_y = vector_get_y(position) + vector_get_y(v_vector);
                    int new_z = vector_get_z(position) + vector_get_z(v_vector);

                    vector_set_x(position, new_x);
                    vector_set_y(position, new_y);
                    vector_set_z(position, new_z);
                }

                Vector *position = punctual_body_get_position(pb);
                printf("pb position (%d,%d,%d)\n",vector_get_x(position), vector_get_y(position), vector_get_z(position));
            }
    }
    

}