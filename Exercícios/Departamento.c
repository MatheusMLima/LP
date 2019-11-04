#include <stdio.h>

int main()
{
      int ano_atual, nascimento, idade;
    printf("Escreva o ano atual (xxxx)\n");
        scanf("%d", &ano_atual);
    printf("Escreva o ano do seu nascimento (xxxx)\n");
        scanf("%d", &nascimento);
    idade = ano_atual-nascimento;
    if (idade >= 18)
        printf("Idade: %d anos\nApto a tirar carteira\n", idade);
    else
        printf("Idade: %d anos\nInapto a tirar carteira\n", idade);
}