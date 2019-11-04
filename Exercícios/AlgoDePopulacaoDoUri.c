#include <stdio.h>
#include <math.h>

int main(void)
{
    int T, PA, PB, cont = 0, anos = 0;
    double G1, G2;
    scanf("%d",&T);
    if ((1<=T)&&(T<=3000)){
        for (cont=0;cont<T;cont++){
            scanf("%d %d %lf %lf",&PA,&PB,&G1,&G2);
            if ((100<=PA<=1000000)&&(PA<PB<=1000000)&&(0.1<=G1<=10.0)&&(0.0<=G2<=10.0)&&(G2<G1)){
                while (PB>=PA){
                    PA = floor(PA+((G1/100)*(PA)));
                    PB = floor(PB+((G2/100)*(PB)));
                    anos++;
                    if (anos>100){
                        printf("Mais de 1 seculo.\n");
                        anos = 0;
                        break;
                    }
                }
            }
            if ((0<anos)&&(anos<=100)){
                printf("%d anos.\n",anos);
                anos = 0;
            }
    }
    }   else{}
}