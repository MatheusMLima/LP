#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100], crip[100];
    int i;
    printf("Digite uma frase para ser criptografada:\n");
    scanf("%[^\n]", frase);
    for(i=0;frase[i]!='\0';i++){
        frase[i] += 3; 
    }
    printf("Sua frase criptografada eh '%s'", frase);
}