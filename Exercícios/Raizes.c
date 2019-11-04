#include <stdio.h>
#include <math.h>

int main()
{
    int A, B, C; 
    float delta, raiz1, raiz2;
    printf("Insira valores para A, B e C:\n");
    scanf("%d %d %d", &A, &B, &C);
    delta = ((B*B))-(4*A)*(C);
    if (delta > 0){
        raiz1 = (-(B)+(sqrt(delta)))/(2*A);
        raiz2 = (-(B)-(sqrt(delta)))/(2*A);
        printf("Raiz 1 = %.2f\nRaiz 2 = %.2f\n", raiz1, raiz2);	
}   if (delta == 0){
        printf("Só existe uma raiz para delta 0\nRaiz: %.2f\n", raiz1);
}   if (delta < 0){
        printf("Nao existe delta negativo\n");
    }