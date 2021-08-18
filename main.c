#include <stdio.h>


void main()
{   float a, b, c, x1=1, x2=1;

    scanf("%f%f%f", &a, &b, &c);

// 1 case of 3, a = 0

    if (a==0  &&  b==0  &&  c==0)
        printf("Many solutions");

    if (a==0  &&  b==0  &&  c!=0)
        printf("No solution");

    if (a==0  &&  b!=0)
    {
        x1 = -c/b;

        printf("%.2f", x1);
    }

// 2 case of 3, D<0, a!=0

    float D = b*b - 4*a*c;

    if (a!=0  &&  D < 0)
        printf( "No solution" );

// 3 case of 3, a!=0 D!=0

    if (a!=0 && D>=0)
    {
        x1 = ( -b + sqrt(D) ) / (2*a);

        x2 = ( -b - sqrt(D) ) / (2*a);

        printf("%.2f \t %.2f", x1, x2);
    }

}

