#include <stdio.h>
#include <float.h>
#include <math.h>
#include "func.h"
#include "test.h"


double newton_demo(double x)
{
    //return 10*atan(20*x*x - 200) + pow(x*x + 1, 0.5);

    //return atan(x - 2.718281828);

    return 1/cos(x);
}

double simpson_demo(double x)
{
    return pow(x, 2) * sin(x);
}

double bisection_demo(double x)
{
    return 3*pow(x, 7) - x + 1;
}

int main(void)
{
    double v=1, x, eps;

    // newton_root_test1();
    // newton_root_test2();
    // newton_root_test3();

    // simpson_integral_test1();
    // simpson_integral_test2();
    // simpson_integral_test3();

    // cos_approx_test1();

    eps = 0.001;
    x = cos_approx(1, eps);

    if(v)
    {
        printf("%lf, %lf\n", x, cos(1));
    } else {
        printf("fail");
    }

    return 0;
}