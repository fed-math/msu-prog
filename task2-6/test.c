#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "func.h"
#include "test.h"


double newton_root_demo(double x);
double simpson_integral_demo1(double x);
double simpson_integral_demo2(double x);
double bisection_minimization_demo(double x);

double newton_root_demo(double x)
{
    return (x-1)*(x-2)*(x-3);
}

double simpson_integral_demo1(double x)
{
    return 1/cos(x);
}

double simpson_integral_demo2(double x)
{
    return sin(x*x);
}


double bisection_minimization_demo(double x)
{
    return (x-1)*(x-2)*(x-3);
}

void newton_root_test1(void)
{
    double epsilon, x;
    int s;

    epsilon = 0.001;
    s = newton_root(&x, 1, 2, newton_root_demo, epsilon);

    if (!s || !(fabs(x - 1) <= epsilon)){
        printf("Test 1 of Newton method FAILED! \n");
        exit(1);
    }

    printf("Test 1 of Newton method PASSED! \n");
}

void newton_root_test2(void)
{
    double epsilon, x;
    int s;

    epsilon = 0.001;
    s = newton_root(&x, 3/2, 5/2, newton_root_demo, epsilon);

    if (!s || !(fabs(newton_root_demo(x)) <= epsilon)){
        printf("Test 2 of Newton method FAILED! \n");
        exit(1);
    }

    printf("Test 2 of Newton method PASSED! \n");
}

void newton_root_test3(void)
{
    double epsilon, x;
    int s;

    epsilon = 0.001;
    s = newton_root(&x, 0, 1/2, newton_root_demo, epsilon);

    if (s){
        printf("Test 3 of Newton method FAILED! \n");
        exit(1);
    }

    printf("Test 3 of Newton method PASSED! \n");
}


void simpson_integral_test1(void)
{
    double eps, x;

    eps = 0.01;

    x = simpson_integral(0, 1, simpson_integral_demo1, eps);

    if(!simpson_check(x, 1.22619117088, 2))
    {
        printf("Test 1 of Simpson integral FAILED! \n");
        exit(1);
    }

    printf("Test 1 of Simpson integral PASSED! \n");
}

void simpson_integral_test2(void)
{
    double eps, x;

    eps = 0.001;

    x = simpson_integral(10, 11, simpson_integral_demo2, eps);

    if(!simpson_check(x, 0.0450104795557, 2))
    {
        printf("Test 2 of Simpson integral FAILED! \n");
        exit(1);
    }

    printf("Test 2 of Simpson integral PASSED! \n");
}

void simpson_integral_test3(void)
{
    double eps, x;

    eps = 0.01;

    x = simpson_integral(0, 1, simpson_integral_demo2, eps);

    if(!simpson_check(x, 0.310268301723, 2))
    {
        printf("Test 3 of Simpson integral FAILED! \n");
        exit(1);
    }

    printf("Test 3 of Simpson integral PASSED! \n");
}


void bisection_minimization_test1(void)
{
    
}


void bisection_minimization_test2(void)
{
    
}


void bisection_minimization_test3(void)
{
    
}



void cos_approx_test1(void)
{
    double eps, x, v;

    eps = 0.001;
    x = 1;

    v = cos_approx(x, 2*eps);
    if (fabs(cos(x) - v) > eps)
    {
        printf("cosine approximation test FAILED!\n");
        exit(1);
    }

    printf("cosine approximation test PASSED!\n");
}