#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100];
    int i, cont=0, aux=0;
    printf("Escreva uma frase:\n");
    scanf("%[^\n]", frase);
    for(i=0;frase[i]!='\0';i++){
        if(frase[i]==65 || frase[i]==97 || frase[i]==69 || frase[i]==101 || frase[i]==73 || frase[i]==105 || frase[i]==79 || frase[i]==111 || frase[i]==85 || frase[i]==117){
            cont++;
            aux++;
        }else if(frase[i]==' ') {
            continue;
        } else {
            aux++;
        }
    }
    printf("Essa frase possui %d vogais/%d caracteres", cont, aux);
}
