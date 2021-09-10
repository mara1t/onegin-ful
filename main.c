#include <stdio.h>

#define NDEBUG_MODE

int find_roots (double a, double b, double c, double *x1, double *x2);
int inputs (double *a, double *b, double *c);
double discriminant(double a, double b, double c);
int more_than_0(double a);
int solve_linear(double k, double b, double* x1);
int output_roots(double a, double b, double c, double* x1, double* x2);
int test_project ();
int check_input (double* a);
const double epsilon = 1e-6;

enum roots
{
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_ROOTS  = 3
};

int main()
{
    #ifndef NDEBUG_MODE
    test_project();
    #else


    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    inputs (&a, &b, &c);
    // вернуть функцию квадратки
    output_roots(a, b, c, &x1, &x2);

    #endif

    return 0;
}

int find_roots (double a, double b, double c, double* x1, double* x2)
{

    if (!more_than_0(a))
    {
        return solve_linear (b, c, &x1);
    }

    double Discr = discriminant(a, b, c);

    if (!more_than_0(Discr))
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
        //  до подсчёта дискриминанта
        if (!more_than_0(c))
        {
            *x2 = 0;
            return solve_linear(a, b, &x1) + 1;
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

int inputs (double* a, double* b, double* c)
{
    printf("Enter coefficient a b c from your equation ax^2+bx+c=0\n"
           "a:");
    // проверка scanf
   /* scanf("%lg", a)
    printf("b:");
    scanf("%lg", b);
    printf("c:");
    scanf("%lg", c);*/
    check_input (a);
    printf("b:");
    check_input (b);
    printf("c:");
    check_input (c);
    return 0;
}
int check_input (double* a)
{
   if (scanf("%lg", a) == 0)
   {
       printf("pls enter right number");
       abort();
   }
   return 0;
}
double discriminant (double a, double b, double c)
{
    return b*b - 4*a*c;
}
int solve_linear (double k, double b, double* x1) // kx+b=0
{   // разбей условия
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
// rename
int more_than_0 (double a)
{
    if (fabs(a) <= epsilon)
        return 0;
    else
        return 1;
}
int output_roots (double a, double b, double c, double* x1, double* x2)
{
    int num_of_roots = find_roots (a, b, c, x1, x2);

    // output_roots
    switch (num_of_roots)
    {
    case ZERO_ROOTS:
        printf("No solution\n");
        break;

    case ONE_ROOT:
        printf("x = %lg\n", *x1);
        break;

    case TWO_ROOTS:
        printf("x1 = %lg\n"
               "x2 = %lg\n", *x1, *x2);
        break;

    case INF_ROOTS:
        printf("many solution\n");
        break;

    default:
        // ERROR
        break;
    }
}
int test_project ()
{
    double x1 = 0, x2 = 0;
    int ERRORS = 0;
    ERRORS += (find_roots(0, 0, 0,  &x1, &x2) != INF_ROOTS)? 1 : 0;
    ERRORS += (find_roots(1, 2, 1,  &x1, &x2) != ONE_ROOT || (x1 != -1))? 1:0;
    ERRORS += (find_roots(0, 0, 1,  &x1, &x2) != ZERO_ROOTS )? 1:0;
    ERRORS += (find_roots(1, 5, 4,  &x1, &x2) != TWO_ROOTS || ( (x1 != -4 && x2 != -1) && (x2 != -4 && x1 != -1) ) )? 1:0;
    ERRORS += (find_roots(1, 3, 2,  &x1, &x2) != TWO_ROOTS || ( (x1 != -1 && x2 != -2) && (x2 != -1 && x1 != -2) ) )? 1:0;
    printf("%d ERRORS\n", ERRORS);
    return 0;
}

