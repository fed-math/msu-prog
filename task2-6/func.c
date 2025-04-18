#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include "func.h"

const double DERIVATIVE_EPSILON = 2 * DBL_EPSILON;
const int NEWTON_ITER_MAX = 1e+6;

int iseq(double x, double y)
{
    return (fabs(x - y) <= (DBL_EPSILON * fabs(x + y)));
}

int fac (int n)
{
    int i, p;

    p = 1;

    for (i=0; i < n; i++)
    {
        p *= i+1;
    }

    return p;
}

double derivative(double x0, dtod f)
{
    double x1, x2, y1, y2;

    x1 = x0 + DERIVATIVE_EPSILON;
    x2 = x0;

    y1 = f(x1);
    y2 = f(x2);

    return (y1-y2)/(x1-x2);
}

int newton_root(double* x, double a, double b, dtod f, double epsilon)
{
    int i;
    double x0, x1, x2;

    if (f(a)*f(b)>0)
    {
        printf("Condition of f(a)f(b) <= 0 is not performed\n");
        return 0;
    }

    if (iseq(f(a), 0)) {
        *x = a;
        return 1;
    }

    if (iseq(f(b), 0))
    {
        *x = b;
        return 1;
    }

    x0 = (a+b)/2; 
    x1 = x0 - f(x0)/derivative(x0, f);
    x2 = x1 - f(x1)/derivative(x1, f);

    for (i=0; i < NEWTON_ITER_MAX; i++)
    {
        // printf("%lf, %lf, %lf \n", x2, f(x2)/derivative(x2, f), derivative(x2, f));
        x0 = x1;
        x1 = x1 - f(x1)/derivative(x1, f);
        x2 = x2 - f(x2)/derivative(x2, f);

        // if(fabs(f(r)) <= epsilon)
        // {
        //     *x = r;
        //     return 1;
        // }

        // if(fabs(s-r) <= epsilon)
        // {
        //     *x = r;
        //     return 1;
        // }

        if (fabs((x2-x1)/(1-(x2-x1)/(x1-x0))) < epsilon)
        {
            *x = x2;
            return 1;
        }
    }

    printf("Number of iterations exceeded \n");

    return 0;

}

double simpson_formula(double a, double b, dtod f)
{
    return ((b-a)/8)*(f(a) + 3*f((2*a+b)/3) + 3*f((a+2*b)/3) + f(b));
}

int simpson_check(double x, double v, int N)
{

    if (floor(pow(10, 4*N)*v) == floor(pow(10, 4*N)*x))
    {
        return 1;
    }

    return 0;
}

double simpson_integral(double a, double b, dtod f, double epsilon)
{
    double I, c;
    int N, i;

    N = floor(1/epsilon) + 1;
    I = 0;
    c = (b - a) / N;

    for (i = 0; i < N; i++)
    {
        I += simpson_formula(a + c*i, a + c*(i+1), f);
    }

    return I;
}

int bisection_minimization(double* x, double a, double b, dtod f, double epsilon)
{
    
}

double quadratic_spline(double a, double b, dtod f)
{
    
}

double cos_approx(double x, double epsilon)
{
    double s, l;
    int i;

    i = 0;
    l = 0;
    s = 1;

    while (fabs(s-l) > epsilon)
    {
        l = s;
        s += pow(-1, (i+1))*pow(x, 2*(i+1))/fac(2*(i+1));
        i++;
    }

    return s;
}