#include <stdio.h>
#include <collision.h>
#include <math.h>
#include <system.h>
#include <vector.h>
#include <punctual_body.h>

int collision_check_collisions(System *s)
{

    if (s->pb_index <= 1)
        return 0;

    printf("tentando colisão\n");
    for (int i = 0; i < s->pb_index; i++)
    {
        PunctualBody *pb1 = s->punctual_bodies[i];
        Vector *pb1_position = punctual_body_get_position(pb1);
        for (int i2 = s->pb_index - 1; i2 >= 0; i2--)
        {
            if (i == i2)
                continue;

            PunctualBody *pb2 = s->punctual_bodies[i2];
            Vector *pb2_position = punctual_body_get_position(pb2);
            int is_equivalent = vector_component_compair(pb1_position, pb2_position);

            if (is_equivalent)
            {
                printf("ocorreu uma colisão!!!\n\n");
                collision_elastic_collision(pb1, pb2);
                return 1;
            }
        }
    }
    return 0;
}

void collision_elastic_collision(PunctualBody *pb1, PunctualBody *pb2)
{
    double linear_momentum1ix, linear_momentum1iy, linear_momentum1iz;
    double linear_momentum2ix, linear_momentum2iy, linear_momentum2iz;

    double hypotenuse_1xy = sqrt(pow(pb1->v->vector->x, 2) + pow(pb1->v->vector->y, 2));
    double hypotenuse_1xz = sqrt(pow(pb1->v->vector->x, 2) + pow(pb1->v->vector->z, 2));

    double v1x = pb1->v->vector->module * (pb1->v->vector->x / hypotenuse_1xy);
    double v1y = pb1->v->vector->module * (pb1->v->vector->y / hypotenuse_1xy);
    double v1z = pb1->v->vector->module * (pb1->v->vector->z / hypotenuse_1xz);

    double hypotenuse_2xy = sqrt(pow(pb2->v->vector->x, 2) + pow(pb2->v->vector->y, 2));
    double hypotenuse_2xz = sqrt(pow(pb2->v->vector->x, 2) + pow(pb2->v->vector->z, 2));
    double v2x = pb2->v->vector->module * (pb2->v->vector->x / hypotenuse_2xy);
    double v2y = pb2->v->vector->module * (pb2->v->vector->y / hypotenuse_2xy);
    double v2z = pb2->v->vector->module * (pb2->v->vector->z / hypotenuse_2xz);

    double v1xf = ((pb1->m - pb2->m) / (pb1->m + pb2->m) * v1x) + ((2 * pb2->m) / (pb1->m + pb2->m)) * v2x;
    double v1yf = ((pb1->m - pb2->m) / (pb1->m + pb2->m) * v1y) + ((2 * pb2->m) / (pb1->m + pb2->m)) * v2y;
    double v1zf = ((pb1->m - pb2->m) / (pb1->m + pb2->m) * v1z) + ((2 * pb2->m) / (pb1->m + pb2->m)) * v2z;

    double v2xf = ((2 * pb1->m) / (pb1->m + pb2->m)) * v1xf - ((pb1->m - pb2->m) / (pb1->m + pb2->m) * v2x);
    double v2yf = ((2 * pb1->m) / (pb1->m + pb2->m)) * v1yf - ((pb1->m - pb2->m) / (pb1->m + pb2->m) * v2y);
    double v2zf = ((2 * pb1->m) / (pb1->m + pb2->m)) * v1zf - ((pb1->m - pb2->m) / (pb1->m + pb2->m) * v2z);

    pb1->v->vector->x = v1xf;
    pb1->v->vector->y = v1yf;
    pb1->v->vector->z = v1zf;
    double resulting_v1f = sqrt(pow(v1xf, 2) + pow(v1yf, 2) + pow(v1zf, 2));
    pb1->v->vector->module = resulting_v1f;

    pb2->v->vector->x = v2xf;
    pb2->v->vector->y = v2yf;
    pb2->v->vector->z = v2zf;
    double resulting_v2f = sqrt(pow(v2xf, 2) + pow(v2yf, 2) + pow(v2zf, 2));
    pb2->v->vector->module = resulting_v2f;
}