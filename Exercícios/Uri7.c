#include <stdio.h>

int main()
{
    int n, x, y, soma, j, i = 0;
    scanf("%d", &n);
    for(i;i<n;i++){
        soma = 0;
        j = 0;
        scanf("%d %d", &x, &y);
        while(j<y){
            if(x%2!=0){
                soma += x;
                j++;
                x++;   
            }   else if(x%2==0){
                    x++;
            }
        }
        printf("%d\n", soma);
    }
}