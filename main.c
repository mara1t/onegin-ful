
#include <stdio.h>

int find_roots (double a, double b, double c, double *x1, double *x2);
int inputs (double *a, double *b, double *c);
double discriminant(double a, double b, double c);
int more_than_0(double a);
int solve_linear(double k, double b, double* x1);
int output_roots(double a, double b, double c, double* x1, double* x2);
int test_project ();
int check_input (double* a);

/**< const for comparing with 0  */
const double epsilon = 1e-6;/// константа для сранения вводимых чисел с нулем

/**< enum is needed to denote the numbers as number of roots */
enum roots
{
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_ROOTS  = 3
};

int main()
{
    test_project();

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    inputs (&a, &b, &c);

    output_roots(a, b, c, &x1, &x2);

    return 0;
}
/** \brief find_roots() is needed to find roots from giving parameters
 *
 * \param 'a' 'b' 'c' param. form equation 'ax^2+bx+c=0'
 * \param x1 and x2 solutions of equation if they exist
 * \return returns number of roots
 *
 */
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
/** \brief inputs() writing words for undestanding function of programm
 *
 * \param a b c param. of equation to count from console
 * \param
 * \return 0 anyway
 *
 */
int inputs (double* a, double* b, double* c)
{
    printf("Enter coefficient a b c from your equation ax^2+bx+c=0\n"
           "a:");
    check_input (a);
    printf("b:");
    check_input (b);
    printf("c:");
    check_input (c);
    return 0;
}
/** \brief checking param. counting from console not to write a letter or symbols instead of number
 *
 * \param a param. is coefficient from equation
 * \param
 * \return 0 anyway
 *
 */
int check_input (double* a)
{
   while (scanf("%lg", a) == 0)
   {
       printf("pls enter right number\n");
       while ( getchar() != '\n')
      {;}
       printf(":");
   }
   return 0;
}
/** \brief counting discriminant while solving equation
 *
 * \param a b c from equation
 * \param
 * \return meaning of discriminant
 *
 */
double discriminant (double a, double b, double c)
{
    return b*b - 4*a*c;
}

/** \brief solving linear equation kx+b=0
 *
 * \param k b from new equation
 * \param x1 is solution of this equation
 * \return number of roots in this equation
 *
 */
int solve_linear (double k, double b, double* x1)
{
    if (!more_than_0(k))
    {
        if (!more_than_0(b))
            return INF_ROOTS;
        else
            return ZERO_ROOTS;
    }
    else
    {
        *x1 = -b / k;
        return ONE_ROOT;
    }
}

/** \brief comparing with 0
 *
 * \param a is param which we are comparing
 * \param
 * \return 0 if a equal to 0, else 1
 *
 */
int more_than_0 (double a)
{
    if (fabs(a) <= epsilon)
        return 0;
    else
        return 1;
}

/** \brief printing solutions of equation
 *
 * \param a b c to find roots
 * \param x1 x2 are wrote on console
 * \return 0
 *
 */
int output_roots (double a, double b, double c, double* x1, double* x2)
{
    int num_of_roots = find_roots (a, b, c, x1, x2);

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

        break;
    }
    return 0;
}

/** \brief testing our project to find out errors
 *
 * \param -
 * \param -
 * \return number of errors
 *
 */
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
