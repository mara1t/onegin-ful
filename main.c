#include <stdio.h>

int find_roots (double a, double b, double c, double *x1, double *x2); // find_sol...
int inputs (double *a, double *b, double *c); //  input_....
double discriminant(double a, double b, double c); // ....
int more_than_0(double a);
int solve_linear(double k, double b, double* x1);
int output_roots(double a, double b, double c, double* x1, double* x2);
// enum + ONE_ROOT + TWO_ROOT
const double epsilon = 1e-6;

enum roots{
ZERO_ROOTS,
ONE_ROOT,
TWO_ROOTS,
INF_ROOTS
};

int main()
{
    double a = 0, b = 2, c = 2, x1 = 2, x2 = 2;

    inputs (&a, &b, &c);

    output_roots(a, b, c, &x1, &x2);

    printf("%lg%lg%lg", a, b, c);
    return 0;
}

int find_roots (double a, double b, double c, double* x1, double* x2)
{
    double Discr = discriminant(a, b, c);

    if (!more_than_0(a))
    {
        return solve_linear (b, c, &x1);
    }
    else if (!more_than_0(Discr))
    {
        *x1 = -b / (2*a);
        return ONE_ROOT;
    }
    else if (Discr < 0)
    {
        return ZERO_ROOTS;
    }
    else if (Discr > 0)
    {
        if (!more_than_0(c))
        {
            *x2 = 0;
            return solve_linear(a, b, &x1)+1;
        }
        else
        {
            double Sq_Di = sqrt(Discr);
            *x1 = ( -b + Sq_Di ) / (2*a);
            *x2 = ( -b - Sq_Di ) / (2*a);
                return TWO_ROOTS;
        }
    }
}

int inputs (double* a, double* b,double* c)
{
    printf("Enter coefficient a b c from your equation ax^2+bx+c=0\n"
           "a:");
    // проверка scanf
    scanf("%lg", a);
    printf("b:");
    scanf("%lg", b);
    printf("c:");
    scanf("%lg", c);
    return 0;
}

double discriminant (double a, double b, double c)
{
    return b*b - 4*a*c;
}
int solve_linear(double k, double b, double* x1) // kx+b=0
{
    if (!more_than_0(k) && !more_than_0(b))
        return INF_ROOTS;
    if (!more_than_0(k) && more_than_0(b))
        return ZERO_ROOTS;
    else
    {
        *x1 = -b / k;
        return ONE_ROOT;
    }
}
int more_than_0(double a)
{
    if (fabs(a) <= epsilon)
        return 0;
    else
        return 1;
}
int output_roots(double a, double b, double c, double* x1, double* x2)
{
    int num_of_roots = find_roots (a, b, c, x1, x2);

    // output_roots
    switch (num_of_roots)
    {
    case ZERO_ROOTS:
        printf("No solution\n");
        break;

    case ONE_ROOT:
        printf("x = %lg\n", x1);
        break;

    case TWO_ROOTS:
        printf("x1 = %lg\n"
               "x2 = %lg\n", x1, x2);
        break;

    case INF_ROOTS:
        printf("many solution\n");
        break;

    default:
        break;
    }
}
