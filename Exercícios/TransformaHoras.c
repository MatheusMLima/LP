#include <stdio.h>
#include <math.h>

#define conv_hrs 3600
#define conv_min 60

int main(void){
    int N, valor, segundos, minutos, horas;
    scanf("%d", &N);
    if (0 < N){
        horas = N/conv_hrs;
        valor = N%conv_hrs;
        minutos = valor/conv_min;
        segundos = valor%conv_min;
    } else {
        printf("Valor não existente");
    }
    printf("%d:%d:%d\n", horas, minutos, segundos);
}