#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, s=0, c=0, i;
    printf("Escreva quantos numeros que serao somados:\n");
    scanf("%d", &n);
    if (n>0){
        while (c<n){
            printf("Insira um numero:\n");
            scanf("%d", &i);
                if (i>0){
                    s= i+s;
                    c++;
                } else {
                    c++;
                }
        }
        printf("A soma eh: %d", s);
    } else {}
}