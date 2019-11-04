#include <stdio.h>

int main (void)
{
   int n, k, i, pow;
   scanf("%d %d", &n, &k);
   pow = n;
   for(i=1;i<k;i++){
       pow = pow*n;
   } 
   printf("A potencia eh: %d", pow);
}