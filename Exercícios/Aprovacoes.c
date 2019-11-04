#include <stdio.h>

int main(void)
{
    double N1, N2, N3, N4, exame, media, media_final;
    scanf("%lf %lf %lf %lf", &N1, &N2, &N3, &N4);
    media = ((N1*0.2)+(N2*0.3)+(N3*0.4)+(N4*0.1)); 
    printf("Media: %.1lf\n", media);
    if (media >= 7.0){
        printf("Aluno aprovado.\n", media);
    }   else if (media < 5.0){
            printf("Aluno reprovado.\n", media);
    }   else if ((5.0 <= media) && (media < 7.0)){
            printf("Aluno em exame.\n");  
            scanf("%lf", &exame);    
            printf("Nota do exame: %.1lf\n", exame);
            media_final = (exame+media)/2.0;     
    if (media_final >= 5.0){
        printf("Aluno aprovado.\n");
        printf("Media final: %.1lf\n", media_final); 
    }   else if (media_final <= 4.9){
            printf("Aluno reprovado.\n");
            printf("Media final: %.1lf\n", media_final); 
    }
    }                  
} 