#include <stdio.h>
#include <math.h>

int main(void)
{
    int X, Y, i, soma=0;
    scanf("%d %d", &X, &Y);
    if (X < Y){
        i = X;
        while (i<=Y){
            if (i%13!=0){
                soma += i;
        }
                    i++;
    }
}   else{
        i = Y;
        while (i<=X){
            if (i%13!=0){
                soma += i;
        }
                    i++;
    }
}   
    printf("%d\n", soma);
}