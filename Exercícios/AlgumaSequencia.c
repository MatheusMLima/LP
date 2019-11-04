#include <stdio.h>
#include <math.h>

int main(void)
{
    double S=0, i=1, j=2;
    while (i<=39){
        i+=2;
        S += i/j;
        j *= 2;
    } 
    S += 1;
    printf("%.2lf\n", S);
}