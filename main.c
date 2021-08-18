#include <stdio.h>

int main()
{
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("Write down coefficient a b c from your equation ax^2+bx+c=0\n"
           "a:");
    scanf("%f", &a);
    printf("b:");
    scanf("%f", &b);
    printf("c:");
    scanf("%f", &c);

// 1 case of 3, a = 0
    if (a == 0){
        if (b == 0 && c == 0){
            printf("Many solutions");
        }
        if (b == 0 && c != 0){
            printf("No solution");
        }
        if (b != 0){
            x1 = -c / b;
            printf("x=%.2f", x1);
        }
    }
// 2 case of 3, D<0, a!=0
    if(a != 0){

        float D = b * b - 4 * a * c;

        if (D < 0){
            printf("No solution");
        }
// 3 case of 3, a!=0 D>=0

        if (D >= 0){
            x1 = ( -b + sqrt(D) ) / (2*a);
            x2 = ( -b - sqrt(D) ) / (2*a);
            printf("x1=%.2f\nx2=%.2f", x1, x2);
        }
    }
    return 0;
}
