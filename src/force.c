#include <stdlib.h>
#include <force.h>


Force *force_new()
{
    Force * f = malloc(sizeof(Force));
    
    Vector *v = vector_new();
    f->v = v;
    
    return f;
}

void force_set_vector(Force *f, Vector *v)
{
    f->v = v;
}

void force_set_module(Force *f, double module)
{
    f->module = module;
}

void force_destroy(Force *f)
{
    free(f);
}