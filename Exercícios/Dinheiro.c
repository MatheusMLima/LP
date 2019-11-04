#include <stdio.h>
#include <math.h>

int main(void)
{
    int valor, nota, nota2, nota4, nota6, nota8, nota10;
    int moeda, valor2, valor3, moeda1, moeda2, moeda3, moeda4, moeda5;
    double valor1, N;
    scanf("%lf", &N);
    if (0 <= N <= 1000000.00){
        valor3 = N/1;
        nota = valor3/100;
        valor = valor3%100;
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
        moeda = valor/1;
        valor = valor%1;
        valor1 = N-valor3;
        valor3 = valor1*100;
        moeda1 = valor3/50;
        valor2 = valor3%50;
        moeda2 = valor2/25;
        valor2 = valor2%25;
        moeda3 = valor2/10;
        valor2 = valor2%10;
        moeda4 = valor2/5;
        valor2 = valor2%5;
        moeda5 = valor2/1;
    }   else {
            printf("Valor inexistente");
    }         
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", nota);
    printf("%d nota(s) de R$ 50.00\n", nota2);
    printf("%d nota(s) de R$ 20.00\n", nota4);
    printf("%d nota(s) de R$ 10.00\n", nota6);
    printf("%d nota(s) de R$ 5.00\n", nota8);
    printf("%d nota(s) de R$ 2.00\n", nota10);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moeda);
    printf("%d moeda(s) de R$ 0.50\n", moeda1);
    printf("%d moeda(s) de R$ 0.25\n", moeda2);
    printf("%d moeda(s) de R$ 0.10\n", moeda3);
    printf("%d moeda(s) de R$ 0.05\n", moeda4);
    printf("%d moeda(s) de R$ 0.01\n", moeda5);
}