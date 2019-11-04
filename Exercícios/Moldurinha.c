#include <stdio.h>

#define NULL ((void*)0)

int main()
{
    char r[10][60];
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<60;j++){
            if((i>0 && i<9) && (j>0 && j<59)){
                r[i][j] = NULL;
            } else {
                r[i][j] = '*';
            }
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<60;j++){
            printf("%c", r[i][j]);
        }
        printf("\n");
    }
}