#include <stdio.h>
#include <string.h>

int main()
{

    int i, n=1;
    char frase[50], aux;
    while(n>0){
        scanf("%[^\n]", &frase);
        setbuf(stdin,NULL);
        if(frase[0]>=97 && frase[0]<=122){
            frase[0] -= 32;
            aux = frase[0];
        }
        for(i=1;frase[i]!='\0';i++){
            if(frase[i-1]>=65 && frase[i-1]<=90){
                if(frase[i]>=65 && frase[i]<=90){
                    frase[i] += 32;
                    aux = frase[i];
                } else if(frase[i]>=97 && frase[i]<=122){
                    aux = frase[i];
                }
            } else if(frase[i-1]>=97 && frase[i-1]<=122){
                if(frase[i]>=65 && frase[i]<=90){
                    aux = frase[i];
                } else if(frase[i]>=97 && frase[i]<=122){
                    frase[i] -= 32;
                    aux = frase[i];
                }
            } else if(frase[i-1]==' '){
                if(aux>=65 && aux<=90){
                    if(frase[i]>=65 && frase[i]<=90){
                        frase[i] += 32;
                        aux = frase[i];
                    } else if(frase[i]>=97 && frase[i]<=122){
                        aux = frase[i];
                    }
                } else if(aux>=97 && aux <=122){
                    if(frase[i]>=97 && frase[i]<=122){
                        frase[i] -= 32;
                        aux = frase[i];
                    } else if(frase[i]>=65 && frase[i]<=90){
                        aux = frase[i];
                    }
                }
            }
        }
    printf("%s\n", frase);
    }
}
