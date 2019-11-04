#include <stdio.h>

int main()
{
    int n,m,i,j;
    printf("Defina o valor de linhas e colunas que tera sua matriz:\n");
    scanf("%d %d", &m, &n);
    if(n&&m <= 0){
        printf("Defina o valor de linhas e colunas que tera sua matriz:\n");
        scanf("%d %d", &n, &m);
    }
    double A[m][n], B[m][n], C[m][n], soma;
    printf("Digite os valores para cada posicao da Matriz A:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Digite os valores para cada posicao da Matriz B:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf", &B[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("|%.1lf|", C[i][j]);
        }
        printf("\n");
    }
}

    
