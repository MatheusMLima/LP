#include <stdio.h>

double media(double n1, double n2, double n3); //media para apenas as duas notas mais altas
double mediaT(double n1, double n2, double n3); //media para as 3 notas

int main()
{                                                                             //como nao sabia qual o peso de cada nota
    double n1, n2, n3, media2, media1;                                        //apenas somei as 2 notas e dividi por 2 no primeiro caso
    printf("Escreva a notas da provas P1, P2 e P3:\n");                       //no segundo caso, somei as 3 e dividi por 3
    scanf("%lf %lf %lf", &n1, &n2, &n3);
    if ((n1 && n2 && n3 >= 0.00) && (n1 && n2 && n3 <= 10.00)){
        media2 = media(n1, n2, n3);
        media1 = mediaT(n1, n2, n3);
        printf("A media das 2 notas mais altas eh: %.2lf\n", media2);
        printf("A media das 3 notas eh: %.2lf\n", media1);
    }
}

double media(double n1, double n2, double n3)
{
    double maiores, media2;
    if (n1 >= n2){
        maiores = n1;
        if (n3 >= n2){
            maiores = n3;
            media2 = maiores/2;
        }   else{
            maiores += n2;
            media2 = maiores/2;
        }
    }   else if (n2 >= n1){
        maiores = n2;
    }   if (n3 >= n1){
            maiores += n3;
            media2 = maiores/2;
        }   else{
            maiores += n1;
            media2 = maiores/2;
        }
    return media2;
}

double mediaT(double n1, double n2, double n3)
{
    double media1;
    media1 = ((n1+n2)+(n3))/3;
    return media1;
}