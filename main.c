#include <stdio.h>

int find_sol(double a, double b, double c, double *x1, double *x2);


int main()
{
    float a = 0, b = 0, c = 0, x1 = 2, x2 = 0, x = 0;

    float D = b * b - 4 * a * c;

    printf("Write down coefficient a b c from your equation ax^2+bx+c=0\n"
           "a:");
    scanf("%f", &a);
    printf("b:");
    scanf("%f", &b);
    printf("c:");
    scanf("%f", &c);

    switch(find_sol(a, b, c, &x1, &x2))
    {
    case 0: printf("No solution\n");
            break;
    case 1: printf("x=%g\n", x1);
            break;
    case 2: printf("x1=%g\nx2=%g\n", x1, x2);
            break;
    case 3: printf("many solution\n");

    }
    return 0;
}

int find_sol(double a, double b, double c, double *x1, double *x2)
{
    double D = b*b - 4*a*c;
    if(a==0){
        if(b==0){
            if(c==0){
                return 3;
            }
            else{
                return 0;
            }
        }
        else{
            *x1=-c/b;
            return 1;
        }
    }
    else if(D == 0){
        *x1=-b/(2*a);
        return 1;
    }
    else if(D != 0){

    *x1 = ( -b + sqrt(D) ) / (2*a);
    *x2 = ( -b - sqrt(D) ) / (2*a);
    return 2;
    }
}



