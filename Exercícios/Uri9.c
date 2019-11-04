#include <stdio.h>

int main()
{
    int N[1000], i, T, j;
    scanf("%d", &T);
    j=0;
    if(2<=T<=50){
        for(i=0;i<1000;i++){
            if(j==T){
                j=0;
            }
            N[i] = j;
            j++; 
        }
    }
    for(i=0;i<1000;i++){
        printf("N[%d] = %d\n", i, N[i]);
    }
}