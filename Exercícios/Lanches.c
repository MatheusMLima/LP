#include <stdio.h>

#define cquente 4.00
#define xsalada 4.50
#define xbacon 5.00
#define torrada 2.00
#define refrigerante 1.50

int main(void)
{
    int i,j;
    double total = 0;
        scanf("%d %d", &i, &j);
        if (i == 1){
            total = (cquente*j);
        }   else if (i == 2){
            total = (xsalada*j);
        }   else if (i == 3){
            total = (xbacon*j);
        }   else if (i == 4){
            total = (torrada*j);
        }   else if (i == 5){
            total = (refrigerante*j);
        }
        printf("Total: R$ %.2lf\n", total);
}
