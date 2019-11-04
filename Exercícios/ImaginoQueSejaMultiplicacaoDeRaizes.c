#include <stdio.h>

int main()
{
    int m,n,p,i,j,k,l;
    printf("De o tamanho para a matriz A:\n");
    scanf("%d %d", &m, &n);
    if(n&&m <= 0){
        printf("De o tamanho para a matriz A:\n");
        scanf("%d %d", &n, &m);
    }
    printf("De o tamanho da coluna da matriz B:\n");
    scanf("%d", &p);
    if(p <= 0){
        printf("De o tamanho da coluna da matriz B:\n");
        scanf("%d", &p);
    }
    double A[m][n], B[n][p], C[m][p];
    printf("Digite os valores para cada posicao da Matriz A:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Digite os valores para cada posicao da Matriz B:\n");
    for(i=0;i<n;i++){
        for(j=0;j<p;j++){
            scanf("%lf", &B[i][j]);
        }
    }
    l = 0;
    for(k=0;k<m;k++){
        for(i=0;i<p;i++){
            C[k][i] = 0;
            for(j=0;j<n;j++){
                C[k][i] += (A[l][j]*B[j][i]);
            }
        }
        l++;
    }
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            printf("|%.1lf|", C[i][j]);
        }
        printf("\n");
    }
}