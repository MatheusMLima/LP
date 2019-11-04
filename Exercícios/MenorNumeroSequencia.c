#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, s=1000000, c=0, i;
    printf("Escreva quantos numeros tera a sua sequencia:\n");
    scanf("%d", &n);
    if (n>0){
        while (c<n){
            printf("Insira um numero:\n");
            scanf("%d", &i);
                    if (i<s){
                    s=i;
                    c++;
                }   else {
                    c++;
                }
        }
        printf("O menor numero eh: %d", s);
    }   else {}
}