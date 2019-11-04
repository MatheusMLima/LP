#include <stdio.h>

int main(void)
{
    int n, i, l, j = 0, k = 1;
    scanf("%d", &n);
    if (n>=0){
        for(i=0;i<n;i++){
            l = j+k;
            j = k;
            k = l;
        }
    }   
    printf("O numero equivale na sequencia ha: %d\n", j);
}