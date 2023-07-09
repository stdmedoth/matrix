#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <energy.h>

MechanicalEnergy *energy_new()
{
    MechanicalEnergy *me = malloc(sizeof(MechanicalEnergy));
    return me;
}

double energy_get_kinect_value(MechanicalEnergy *me)
{
    double module = me->kine.v->vector->module;
    double value = ((me->kine.m * pow(module, 2)) / 2);

    return value;
}

void energy_destroy(MechanicalEnergy *me)
{
    free(me);
}
