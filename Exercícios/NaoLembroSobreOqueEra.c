#include <stdio.h>
#include <string.h>

int main()
{
    int n,a,i,sub,sub1,sub2,sub3,soma,soma1,soma2,soma3,divv,div1,div2,div3,mut,mut1,mut2,mut3;
    char C1, C2, C3;
    struct Contas{
        int N1, D1;
    };
    struct Contas f1;
    struct Contas f2;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        a=2;
        scanf("%d", &f1.N1);
        getchar();
        scanf("%s", &C1);
        scanf("%d", &f1.D1);
        getchar();
        scanf("%s", &C2);
        scanf("%d", &f2.N1);
        getchar();
        scanf("%s", &C3);
        scanf("%d", &f2.D1);
        if((C2) == '-'){
            sub = (f1.N1*f2.D1) - (f2.N1*f1.D1);
            sub1 = (f1.D1*f2.D1);
            sub2 = sub;
            sub3 = sub1;
            while(a<sub2 && a<sub3){
                if(sub2%a==0 && sub3%a==0){
                    sub2 = sub2/a;
                    sub3 = sub3/a;
                } else {
                    a++;
                }
            }
            printf("%d/%d = %d/%d\n", sub,sub1,sub2,sub3);
        } else if((C2) == '+'){
            soma = (f1.N1*f2.D1) + (f2.N1*f1.D1);
            soma1 = (f1.D1*f2.D1);
            soma2 = soma;
            soma3 = soma1;
            while(a<soma2 && a<soma3){
                if(soma2%a==0 && soma3%a==0){
                    soma2 = soma2/a;
                    soma3 = soma3/a;
                } else {
                    a++;
                }
            }
            printf("%d/%d = %d/%d\n", soma,soma1,soma2,soma3);
        } else if((C2) == '/'){
            divv = (f1.N1*f2.D1);
            div1 = (f2.N1*f1.D1);
            div2 = divv;
            div3 = div1;
            while(a<div2 && a<div3){
                if(div2%a==0 && div3%a==0){
                    div2 = div2/a;
                    div3 = div3/a;
                } else {
                    a++;
                }
            }
            printf("%d/%d = %d/%d\n", divv,div1,div2,div3);
        } else if((C2) == '*'){
            mut = (f1.N1*f2.N1);
            mut1 = (f1.D1*f2.D1);
            mut2 = mut;
            mut3 = mut1;
            while(a<mut2 && a<mut3){
                if(mut2%a==0 && mut3%a==0){
                    mut2 = mut2/a;
                    mut3 = mut3/a;
                } else {
                    a++;
                }
            }
            printf("%d/%d = %d/%d\n", mut,mut1,mut2,mut3);
        }
    }
}
