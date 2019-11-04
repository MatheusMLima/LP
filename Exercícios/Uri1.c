#include <stdio.h>

int main()
{
    int x, z, i, j, a = 1;
    scanf("%d %d", &x, &z);
    while(x>=z){
        scanf("%d", &z);
    }
    i = x++;
    while(x<z){
        x += i;
        i++;
        a++;
    }
    printf("%d\n", a);
}