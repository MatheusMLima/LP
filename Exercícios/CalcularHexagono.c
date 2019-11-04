#include <stdio.h>
#include <math.h>

void calcula_hexagono(double l, double *area, double *perimetro);

int main()
{
    double area, perimetro, l;
    scanf("%lf", &l);
    calcula_hexagono(l,&area,&perimetro);
    printf("area = %.3lf\nperimetro = %.3lf\nlado = %.3lf\n", area, perimetro, l);
}

void calcula_hexagono(double l, double *area, double *perimetro)
{
    *area = ((3.0*(pow(l,2.0)))*sqrt(3.0))/2.0;
    *perimetro = (6.0*l);
}
