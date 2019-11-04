#include <stdio.h>

int main()
{
    int N[20], i, aux, Y;
    for(i=0;i<20;i++){
        scanf("%d", &N[i]);
    }
    Y=19;
    for(i=0;i<10;i++){
        aux = N[i];
        N[i] = N[Y];
        N[Y] = aux;
        Y--;
    }
    for(i=0;i<20;i++){
        printf("N[%d] = %d\n", i, N[i]);
    }
}