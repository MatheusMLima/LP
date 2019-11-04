# include <stdio.h>

double ordenacao(double uniao[], int m, int n);

int main()
{
    int n, m, i, j, k = 0, a, b;
    printf("Escolha quantos valores tera sua sequencia para x:\n");
    scanf("%d", &n);
    double x[n], aux;
    printf("Monte sua sequencia para x:\n");
    for(i=0;i<n;i++){
        scanf("%lf", &x[i]);
    }   for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(x[i]>x[j]){
                    aux=x[i];
                    x[i]=x[j];
                    x[j]=aux;
                }
            }
        }
    printf("Escolha quantos valores tera sua sequencia para y:\n");
    scanf("%d", &m);
    double y[m], uniao[m+n], uniao_o[m+n];
    printf("Monte sua sequencia para y:\n");
    for(i=0;i<m;i++){
        scanf("%lf", &y[i]);
    }   for(i=0;i<m;i++){
            for(j=i+1;j<m;j++){
                if(y[i]>y[j]){
                    aux=y[i];
                    y[i]=y[j];
                    y[j]=aux;
                }
            }
        }
        j=0;
        for(i=0;i<m;i++){
            uniao[i] = y[j];
            j++;
        }
        j=0;
        for(i=m;i<m+n;i++){
            uniao[i] = x[j];
            j++;
        }
    uniao_o[m+n]=ordenacao(uniao,m,n);
    for(i=0;i<m+n;i++){
        printf("O valor da uniao eh: %.2lf\n", uniao[i]);
    }
    for(i=0;i<m+n;i++){
        for(j=i+1;j<m+n;j++){
            if(uniao[i]==uniao[j]){
                uniao[j]=0;
            }
        }
    }
    for(i=0;i<m+n;i++){
        printf("O valor da uniao sem repeticao eh: %.2lf\n", uniao[i]);
    }
    uniao_o[m+n]=ordenacao(uniao,m,n);
    for(i=0;i<m+n;i++){
        printf("O valor da uniao ordenada sem repeticao eh: %.2lf\n", uniao[i]);
    }
}

double ordenacao(double uniao[], int m, int n)
{
    double uniao_o[m+n], aux;
    int i,j;
    for(i=0;i<m+n;i++){
        for(j=i+1;j<m+n;j++){
            if(uniao[i]>uniao[j]){
                aux=uniao[i];
                uniao[i]=uniao[j];
                uniao[j]=aux;
            }
        }
    }
    return uniao_o[m+n];
}
