#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade, ano_de_nascimento, ano_atual, mes;

    printf("Quando voce nasceu? \n");
    scanf("%d", &ano_de_nascimento);

    printf("Em que ano voce esta? \n");
    scanf("%d", &ano_atual);

    printf("Qual o numero do mes voce nasceu? \n");
    scanf("%d", &mes);
    if ((mes == 1) || (mes == 2) || (mes == 3))
        printf("Sua idade sera de %d anos \n", ano_atual-ano_de_nascimento);
    else
        printf("Sua idade sera de %d anos \n", ano_atual-1-ano_de_nascimento);

    return 0;
}
