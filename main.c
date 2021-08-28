#include <stdio.h>

int find_sol (double a, double b, double c, double *x1, double *x2);
int inputing (double *a, double *b,double *c);

const int INF_ROOTS = 3;

int main()
{
    double a = 0, b = 2, c = 2, x1 = 2, x2 = 2;

    inputing(&a, &b, &c);


    int num_of_roots = find_sol (a, b, c, &x1, &x2);

    switch (num_of_roots)
    {
    case 0: printf("No solution\n");
            break;
    case 1: printf("x=%lg\n", x1);
            break;
    case 2: printf("x1=%lg\nx2=%g\n", x1, x2);
            break;
    case 3 : printf("many solution\n");
            break;
    default:break;
    }
   // printf("%lg %lg %lg", a,b,c);
    return 0;
}

int find_sol(double a, double b, double c, double* x1, double* x2)
{
    double Discr = b * b - 4*a*c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return INF_ROOTS;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else if (Discr == 0)
    {
        *x1 = -b / (2*a);
        return 1;
    }
    else if (Discr < 0)
    {
        return 0;
    }
    else if (Discr > 0)
    {
        if (c == 0)
        {
            *x1 = 0;
            *x2 = -b / a;
            return 2;
        }
        else
        {
            double Sq_Di = sqrt(Discr);
            *x1 = ( -b + Sq_Di ) / (2*a);
            *x2 = ( -b - Sq_Di ) / (2*a);
            return 2;
        }
    }
}
int inputing(double* a, double* b,double* c)
{
    printf("Enter coefficient a b c from your equation ax^2+bx+c=0\n"
           "a:");
    scanf("%lg", a);
    printf("b:");
    scanf("%lg", b);
    printf("c:");
    scanf("%lg", c);
    return 0;
}
/*int one_sol()
{

}*/
