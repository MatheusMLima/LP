#include <stdio.h>
#include <math.h>

int main()
{
    int N, valor, nota, nota2, nota4, nota6, nota8, nota10, nota12;
    scanf("%d", &N);
    if (0 < N < 1000000){
        nota = N/100;
        valor = N%100;
        nota2 = valor/50;
        valor = valor%50;
        nota4 = valor/20;
        valor = valor%20;
        nota6 = valor/10;
        valor = valor%10;
        nota8 = valor/5;
        valor = valor%5;
        nota10 = valor/2;
        valor = valor%2;
        nota12 = valor/1;
    }   else {
            printf("Valor inexistente");
    }         
    printf("%d\n", N);
    printf("%d nota(s) de R$ 100,00\n", nota);
    printf("%d nota(s) de R$ 50,00\n", nota2);
    printf("%d nota(s) de R$ 20,00\n", nota4);
    printf("%d nota(s) de R$ 10,00\n", nota6);
    printf("%d nota(s) de R$ 5,00\n", nota8);
    printf("%d nota(s) de R$ 2,00\n", nota10);
    printf("%d nota(s) de R$ 1,00\n", nota12);
}