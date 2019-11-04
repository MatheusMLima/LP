#include <stdio.h>
#include <math.h>

int main(void)
{
    double R1, R2, a, b, c, delta; 
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = ((b*b))-(4*a)*(c);
    if ((delta > 0) && (a!=0)){
        R1 = (-(b)+(sqrt(delta)))/(2*a);
        R2 = (-(b)-(sqrt(delta)))/(2*a);
        printf("R1 = %.5lf\nR2 = %.5lf\n", R1, R2);
    }   else if ((delta < 0) || (a==0)){
            printf("Impossivel calcular\n");
    }   else if ((delta == 0) || (a==0)){
            printf("Impossivel calcular\n");  
    }   
}