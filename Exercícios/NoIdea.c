#include <stdio.h>

double s(double Ma[12][12]);

int main()
{
    int i,j;
    double Ma[12][12], media, soma=0;
    char O;
    scanf("%s", &O);
    if(O=='S'){
            for(i=0;i<12;i++){
                for(j=0;j<12;j++){
                    scanf("%lf", &Ma[i][j]);
                }
            }
            soma = s(Ma);
            printf("%.1lf\n", soma);
    }   else if(O=='M'){
            for(i=0;i<12;i++){
                for(j=0;j<12;j++){
                    scanf("%lf", &Ma[i][j]);
                }
            }
            soma = s(Ma);
            media = soma/66;
            printf("%.1lf\n", media);
    }
}

double s(double Ma[12][12])
{
    int i,j;
    double soma;
    for(i=0;i<12;i++){
        for(j=i+1;j<12;j++){
            soma += Ma[i][j];
        }
    }
    return soma;
}