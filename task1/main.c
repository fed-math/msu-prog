#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "test.h"

double sum(double a, double b);

double mult(double a, double b);

double sum(double a, double b)
{
    return a + b;
}

double mult(double a, double b)
{
    return a*b;
}

int main(void)
{
    int n, i, j;
    double* x,* y;

    dot_prod_test1();
    dot_prod_test2();
    dot_prod_test3();
    dot_prod_test4();
    dot_prod_test5();
    
    printf("Enter vectors length: \n");
    scanf("%d", &n);
    printf("\n");
    
    x = (double*)malloc(n * sizeof(double));
    y = (double*)malloc(n * sizeof(double));


    printf("Enter components of vector x: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", x+i);
        printf("\n");
    }

    printf("Enter components of vector y: \n");
    for (j = 0; j < n; j++)
    {
        scanf("%lf", y+j);
        printf("\n");
    }
    printf("%lf\n", *x);
    printf("dot product of x and y is %lf", dot_prod(n, x, y, sum, mult));    

    free(x);
    free(y);

    return 0;
}