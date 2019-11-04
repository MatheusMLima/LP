#include <stdio.h>

int main()
{
    int jogador1 = 0, jogador2 = 0, contador = 0, moeda;
    while (contador < 10){ 
        printf("Escolha 1(cara) ou 2(coroa)\n");
        scanf("%d", &moeda);
        if (moeda==1)
            jogador1++;
        else
            jogador2++;
            contador++;
    }
    if (jogador1 > jogador2)
    printf("Jogador 1 venceu");
    if (jogador2 > jogador1)
    printf("Jogador 2 venceu");
    if (jogador1 == jogador2)
    printf("Empate"); 
}