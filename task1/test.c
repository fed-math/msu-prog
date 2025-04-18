#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "func.h"

double sum1(double a, double b);

double sum1(double a, double b);

double mult1(double a, double b);

double mult2(double a, double b);

double sum1(double a, double b)
{
    return a + b;
}

double sum2(double a, double b)
{
    return 3*a + 2*b;
}

double mult1(double a, double b)
{
    return a*b;
}

double mult2(double a, double b)
{
    return a + 2*a*b;
}

void dot_prod_test1()
{
    double* x;
    double* y;
    double v;

    x = (double*)malloc(2*sizeof(double));
    y = (double*)malloc(2*sizeof(double));

    *(x+0) = 1;
    *(x+1) = 2;
    *(y+0) = -1;
    *(y+1) = 1;

    v = dot_prod(2, x, y, sum1, mult1);
    
    if(!iseq(v, 1))
    {
        printf("Test 1 of dot product FAILED!\n");
        free(x);
        free(y);
        exit(1);
    }

    printf("Test 1 of dot product PASSED!\n");
    free(x);
    free(y);
}

void dot_prod_test2()
{
    double* x;
    double* y;
    double v;

    x = (double*)malloc(2*sizeof(double));
    y = (double*)malloc(2*sizeof(double));

    *(x+0) = 1;
    *(x+1) = -1;
    *(y+0) = -1;
    *(y+1) = 2;

    v = dot_prod(2, x, y, sum2, mult1);

    if(!iseq(v, -7))
    {
        printf("Test 2 of dot product FAILED!\n");
        free(x);
        free(y);
        exit(1);
    }

    printf("Test 2 of dot product PASSED!\n");
    free(x);
    free(y);
}

void dot_prod_test3()
{
    double* x;
    double* y;
    double v;

    x = (double*)malloc(2*sizeof(double));
    y = (double*)malloc(2*sizeof(double));

    *(x+0) = 0;
    *(x+1) = 0;
    *(y+0) = 1;
    *(y+1) = 1;

    v = dot_prod(2, x, y, sum1, mult2);

    if(!iseq(v, 0))
    {
        printf("Test 3 of dot product FAILED!\n");
        free(x);
        free(y);
        exit(1);
    }

    printf("Test 3 of dot product PASSED!\n");
    free(x);
    free(y);
}

void dot_prod_test4()
{
    double* x;
    double* y;
    double v;

    x = (double*)malloc(2*sizeof(double));
    y = (double*)malloc(2*sizeof(double));

    *(x+0) = 1;
    *(x+1) = 2;
    *(y+0) = 2;
    *(y+1) = 1;

    v = dot_prod(2, x, y, sum2, mult2);

    if(!iseq(v, 27))
    {
        printf("Test 4 of dot product FAILED!\n");
        free(x);
        free(y);
        exit(1);
    }

    printf("Test 4 of dot product PASSED!\n");
    free(x);
    free(y);
}

void dot_prod_test5()
{
    double* x;
    double* y;
    double v;

    x = (double*)malloc(2*sizeof(double));
    y = (double*)malloc(2*sizeof(double));

    *(x+0) = 1;
    *(x+1) = 2;
    *(x+2) = 3;
    *(y+0) = -1;
    *(y+1) = 1;
    *(y+2) = 5;

    v = dot_prod(3, x, y, sum1, mult1);

    if(!iseq(v, 16))
    {
        printf("Test 5 of dot product FAILED!\n");
        free(x);
        free(y);
        exit(1);
    }

    printf("Test 5 of dot product PASSED!\n");
    free(x);
    free(y);
}
