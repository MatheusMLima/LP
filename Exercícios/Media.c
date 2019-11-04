#include <stdio.h>

int main(){

    float p1, p2, media;
    printf("Coloque a nota da primeira prova:\n");
    scanf("%f", &p1);
    printf("Coloque a nota da segunda prova:\n");
    scanf("%f", &p2);
    if  (p1 < 0 || p1 > 10 || p2 < 0 || p2 > 10){
        printf("Valores inexistentes\n");
    }else{
        media = (p1+p2)/2;
    if (media >= 7){
        printf("MEDIA: %.2f\nALUNO APROVADO\n", media);
    }else{
        printf("MEDIA: %.2f\nALUNO REPROVADO\n", media);
    }
    }
}
