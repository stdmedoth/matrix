#ifndef __MATRIX_ENERGY__
#define __MATRIX_ENERGY__

typedef struct _kinect_energy
{
    double m;
    double v;
    double value;

} KinectEnergy;


typedef struct _elastic_energy
{
    double x;
    double k;
    double value;

} ElasticEnergy;

typedef struct _gravitational_energy
{
    double m;
    double h;
    double a;
    double value;

} GravitationalEnergy;

typedef struct _mechanical_energy
{
    KinectEnergy kine;
    GravitationalEnergy grav;
    ElasticEnergy elas;
    double value;

} MechanicalEnergy;

#endif