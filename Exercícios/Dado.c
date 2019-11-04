#include <stdio.h>

int main()
{
    int n;
    printf("Quantas vezes voce jogou o dado?\n");
    scanf("%d", &n);
    int r[n], i, um=0, dois=0, tres=0, quatro=0, cinco=0, seis=0;
    printf("Quais foram os resultados de cada jogada? Respectivamente\n");
    for(i=0;i<n;i++){
        scanf("%d", &r[i]);
        if((r[i]<=0) || (r[i]>=7)){
            printf("Por favor, insira um numero de 1 a 6!\n");
            scanf("%d", &r[i]);
        }
    }
    for(i=0;i<n;i++){
        switch(r[i])
        {
            case 1:
                um++;
                break;
            case 2:
                dois++;
                break;
            case 3:
                tres++;
                break;
            case 4:
                quatro++;
                break;
            case 5:
                cinco++;
                break;
            case 6:
                seis++;
                break;
            default:
                break;
        }
    }
    printf("A face 1 ocorreu %d vez(es)!\n", um);
    printf("A face 2 ocorreu %d vez(es)!\n", dois);
    printf("A face 3 ocorreu %d vez(es)!\n", tres);
    printf("A face 4 ocorreu %d vez(es)!\n", quatro);
    printf("A face 5 ocorreu %d vez(es)!\n", cinco);
    printf("A face 6 ocorreu %d vez(es)!\n", seis);
}
