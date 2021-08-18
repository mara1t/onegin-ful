#include <stdio.h>


void main()
{   float a, b, c, x1=1, x2=1;

    scanf("%f%f%f", &a, &b, &c);

// 1 случай из 3, a = 0

    if (a==0  &&  b==0  &&  c==0)
        printf("уравнение имеет бесконечное множество решений");

    if (a==0  &&  b==0  &&  c!=0)
        printf("уравнение не имеет решений");

    if (a==0  &&  b!=0)
    {
        x1 = -c/b;

        printf("%.2f", x1);
    }

// 2 случай из 3, D<0, a!=0

    float D = b*b - 4*a*c;

    if (a!=0  &&  D < 0)
        printf( "нет решений" );

// 3 случай из 3, a!=0 D!=0

    if (a!=0 && D>=0)
    {
        x1 = ( -b + sqrt(D) ) / (2*a);

        x2 = ( -b - sqrt(D) ) / (2*a);

        printf("%.2f \t %.2f", x1, x2);
    }

}

