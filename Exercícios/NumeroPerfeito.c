#include <stdio.h>
#include <math.h>

int main (void)
{
    int N, X, cont = 1, soma = 0, cont2 = 0;
    scanf("%d", &N);
    if (1 <= N <= 20){
        for (cont2; cont2<N; cont2++){
            scanf("%d", &X);
            if (1 <= X <= 1000000000){
                for (cont; cont<X; cont++){
                    if (X%cont==0){
                        soma += cont;
                    }   else{}
                }
                if (X == soma){
                    printf("%d eh perfeito\n", X);
                    cont = 1;
                    soma = 0;
                }   else{
                    printf("%d nao eh perfeito\n", X);
                    cont = 1;
                    soma = 0;
                }
            }   else{}
        }
    }   else {}
}