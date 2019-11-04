#include <stdio.h>

int main(void)
{
    double valor;
    scanf("%lf", &valor);
        if ((0.00 <= valor) && (valor <= 25.00)){
            printf("Intervalo [0,25]\n");
    }   else if ((25.01 <= valor) && (valor <= 50.00)){
            printf("Intervalo (25,50]\n");
    }   else if ((50.01 <= valor) && (valor <= 75.00)){
            printf("Intervalo (50,75]\n");
    }   else if ((75.01 <= valor) && (valor <= 100.00)){
            printf("Intervalo (75,100]\n");
    }   else {
        printf("Fora de intervalo\n");
    }
}