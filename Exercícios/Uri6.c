#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,n,cont=0, aux, aux1;
    char l[100],s;
    scanf("%d", &n);
    setbuf(stdin,NULL);
    for(i=0;i<n;i++){
        scanf("%[^\n]", &l);
        setbuf(stdin,NULL);
        for(j=0;l[j]!='\0';j++){
            cont++;
        }
        if(cont%2==0){
            aux = (cont/2)-1;
            for(j=0;j<aux;j++){
                aux1 = l[j];
                l[j] = l[aux];
                l[aux] = aux1;
                aux--;
            }
            aux = (cont/2);
            cont -= 1;
            for(j=aux;j<cont;j++){
                aux1 = l[j];
                l[j] = l[cont];
                l[cont] = aux1;
                cont--;
            }
            printf("%s", l);
        }
        printf("\n");
        cont = 0;
    }
}