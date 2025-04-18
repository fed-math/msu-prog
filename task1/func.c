#include <float.h>
#include <math.h>
#include "func.h"

int iseq(double x, double y)
{
    return (fabs(x - y) <= (DBL_EPSILON * fabs(x + y)));
}

double dot_prod(int n, double* x, double* y, double (*sum)(double, double), double (*mult)(double, double))
{
    int i;
    double s;

    s = 0;

    for (i = 0; i < n; i++)
    {
        if (!i)
        {
            s = mult(*(x+i), *(y+i));
        } else {
            s = sum(s, mult(*(x+i), *(y+i)));
        }
    }

    return s;
}