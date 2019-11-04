#include <stdio.h>

#define NULL ((void *)0)

int main()
{
   int impar[5], par[5], i, j, k, l, aux;
   k=0;
   l=0;
   for(i=0;i<15;i++){
       scanf("%d", &aux);
       if(aux%2==0){
           par[l] = aux;
           l++;
           if(l==5){
               l=0;
               for(j=0;j<5;j++){
                   printf("par[%d] = %d\n", j, par[j]);
               }
               for(j=0;j<5;j++){
                   par[j] = NULL;
               }
           }
       } else if(aux%2!=0){
           impar[k] = aux;
           k++;
           if(k==5){
               k=0;
               for(j=0;j<5;j++){
                   printf("impar[%d] = %d\n", j, impar[j]);
               }
               for(j=0;j<5;j++){
                   impar[j] = NULL;
               }
           }
       }
    }
        for(j=0;j<5;j++){
            if(impar[j]==NULL){   
            } else{
                printf("impar[%d] = %d\n", j, impar[j]);
            }
        }
        for(j=0;j<5;j++){
            if(par[j]==NULL){
            } else{
                printf("par[%d] = %d\n", j, par[j]);
            }
        }
}