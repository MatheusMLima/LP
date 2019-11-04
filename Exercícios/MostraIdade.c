#include <stdio.h>
#include <math.h>

#define ano 365
#define mes 30

int main(void){
    int dias_vida, dias, meses, anos, valor;
    scanf("%d", &dias_vida);
    if (dias_vida > 0){
        anos = dias_vida/ano;
        valor = dias_vida%ano;
        meses = valor/mes;
        dias = valor%mes;
    } else {
        printf("Valor inexistente");
    }
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
}