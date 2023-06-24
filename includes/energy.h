#include <velocity.h>
#ifndef __MATRIX_ENERGY__
#define __MATRIX_ENERGY__

typedef struct _kinect_energy
{
    double m;
    Velocity *v;

} KinectEnergy;


typedef struct _elastic_energy
{
    Vector *xi,*xf;
    double k;

} ElasticEnergy;

typedef struct _gravitational_energy
{
    double m;
    double r;
    double g;
} GravitationalEnergy;

typedef struct _mechanical_energy
{
    KinectEnergy kine;
    GravitationalEnergy grav;
    ElasticEnergy elas;
    double value;

} MechanicalEnergy;



MechanicalEnergy *energy_new();
void energy_destroy(MechanicalEnergy *me);


double energy_get_kinect_value(MechanicalEnergy *me);

#endif