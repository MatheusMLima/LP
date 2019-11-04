#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j,a[123],k,p,m;
    char l[200],s;
    scanf("%d", &n);
    setbuf(stdin,NULL);
    for(i=0;i<n;i++){
        scanf("%[^\n]", &l);
        setbuf(stdin,NULL);
        for(j=97;j<123;j++){
            a[j]=0;
        }
        m = 0;
        for(k=0;l[k]!='\0';k++){
            if(l[k]>=65 && l[k]<=90){
                l[k] += 32;
            }
            if(l[k]>=97 && l[k]<=122){
                p = l[k];
                a[p] = a[p]+1;
                if(a[p]>m){
                    m = a[p];
                }
            }
        }
        for(s=97;s<123;s++){
            if(a[s]==m){
                printf("%c", s);
            }
        }
        printf("\n");
    }
}