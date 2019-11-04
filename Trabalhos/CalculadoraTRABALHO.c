#include <stdio.h>
#include <math.h>

#define cos60 0.5
#define cos90 0.0
#define cos180 -1.0
#define cos270 0.0
#define cos360 1.0
#define seno30 0.5
#define seno90 1.0
#define seno180 0.0
#define seno270 -1.0
#define seno360 0.0

double soma(double x, double y);
double subtracao(double x, double y);
double divi(double x, double y);
double mut(double x, double y);
double raiz(double x);
double pot(double x, double y);
double pot_neg(double x, double y);
int fatorial(int p);

int main()
{
    double x, y, historico[5] = {0,0,0,0,0}, s, sub, d, m, r, po, l, fa;
    int i, c = 1, a = 0, p, fat, b=1, ln, t;

    while (c>0){
        printf("============================//\\Calculadora do Teteu//\\============================\n\n\n\n");
        printf("-----------------Escolha qual operacao sera feita:-----------------\n\n");
        printf("1. Adicao\n2. Subtracao\n3. Divisao\n4. Multiplicacao\n5. Raiz quadrada\n6. Potencia\n7. Seno\n8. Cosseno\n");
        printf("9. Logaritmo natural\n10. Fatorial\n11. Historico das 5 ultimas operacoes\n12. Desligar\n");
        scanf("%d", &i);
        if (i<1 || i>12){
        }   else{
                switch (i){
                    case 1:
                            printf("Insira o valor e por quanto quer soma-lo:\n");
                            scanf("%lf %lf", &x, &y);
                            s = soma(x,y);
                            printf("X: %lf\nY: %lf\nResultado: %lf\n\n\n\n\n", x, y, s);
                            historico[a] = s;
                            a++;
                            if(a==5){
                                a = 0;
                            }
                        break;
                    case 2:
                            printf("Insira o valor e por quanto quer subtrai-lo:\n");
                            scanf("%lf %lf", &x, &y);
                            sub = subtracao(x,y);
                            printf("X: %lf\nY: %lf\nResultado: %lf\n\n\n\n\n", x, y, sub);
                            historico[a] = sub;
                            a++;
                            if(a==5){
                                a = 0;
                            }
                        break;
                    case 3:
                            printf("Insira o valor que ira ser dividido e por quanto quer dividi-lo:\n");
                            scanf("%lf %lf", &x, &y);
                            if ((y>0) || (y<0)){
                                d = divi(x,y);
                                printf("Dividendo: %lf\nDivisor: %lf\nQuociente: %lf\n\n\n\n\n", x, y, d);
                                historico[a] = d;
                                a++;
                                if(a==5){
                                    a = 0;
                                }
                            } else if (y==0) {
                                printf("Nao existe divisao por 0\n\n\n\n\n");
                            }
                        break;
                    case 4:
                            printf("Insira o valor que ira ser mutiplicado e por quanto quer mutiplica-lo:\n");
                            scanf("%lf %lf", &x, &y);
                            m = mut(x,y);
                            printf("Multiplicando: %lf\nMultiplicador: %lf\nProduto: %lf\n\n\n\n\n",x, y, m);
                            historico[a] = m;
                            a++;
                            if(a==5){
                                a = 0;
                            }
                        break;
                    case 5:
                            printf("Insira o valor:\n");
                            scanf("%lf", &x);
                            if (x >= 0){
                                r = raiz(x);
                                printf("Valor: %lf\nRaiz Quadrada: %lf\n\n\n\n\n", x, r);
                                historico[a] = r;
                                a++;
                                if(a==5){
                                    a = 0;
                                }
                            }   else{
                                    printf("Resultado Indefinido\n\n\n\n\n");
                            }
                        break;
                    case 6:
                            printf("Insira o valor da base e seu expoente:\n");
                            scanf("%lf %lf", &x, &y);
                            if(y>0){
                                po = pot(x,y);
                                printf("Base: %lf\nExpoente: %lf\nResultado: %lf\n\n\n\n\n", x, y, po);
                                historico[a] = po;
                                a++;
                                if(a==5){
                                    a = 0;
                                }
                            }   else if (y<0){
                                    po = pot_neg(x,y);
                                    printf("Base: %lf\nExpoente: %lf\nResultado: %lf\n\n\n\n\n", x, y, po);
                                    historico[a] = po;
                                    a++;
                                    if(a==5){
                                        a = 0;
                                    }
                            }   else if (y==0){
                                    po = 1;
                                    printf("Base: %lf\nExpoente: %lf\nResultado: %lf\n\n\n\n\n", x, y, po);
                                    historico[a] = po;
                                    a++;
                                    if(a==5){
                                        a = 0;
                                    }
                            }
                        break;
                    case 7:
                            printf("Insira o valor:\n");
                            scanf("%lf", &x);
                            if (x == 30){
                                printf("Valor: %lf\nSeno: %lf\n\n\n\n\n", x, seno30);
                                historico[a] = seno30;
                                a++;
                            }   else if (x == 90) {
                                    printf("Valor: %lf\nSeno: %lf\n\n\n\n\n", x, seno90);
                                    historico[a] = seno90;
                                    a++;
                            }   else if (x == 180) {
                                    printf("Valor: %lf\nSeno: %lf\n\n\n\n\n", x, seno180);
                                    historico[a] = seno180;
                                    a++;
                            }   else if (x == 270) {
                                    printf("Valor: %lf\nSeno: %lf\n\n\n\n\n", x, seno270);
                                    historico[a] = seno270;
                                    a++;
                            }   else if (x == 360) {
                                    printf("Valor: %lf\nSeno: %lf\n\n\n\n\n", x, seno360);
                                    historico[a] = seno360;
                                    a++;
                            }   else {
                                    printf("Valor: %lf\nSeno: %lf\n\n\n\n\n", x, sin(x));
                                    historico[a] = sin(x);
                                    a++;
                            }
                                if(a==5){
                                    a = 0;
                                }
                        break;
                    case 8:
                            printf("Insira o valor:\n");
                            scanf("%lf", &x);
                            if (x == 60){
                                printf("Valor: %lf\nCosseno: %lf\n\n\n\n\n", x, cos60);
                                historico[a] = cos60;
                                a++;
                            }   else if (x == 90) {
                                    printf("Valor: %lf\nCosseno: %lf\n\n\n\n\n", x, cos90);
                                    historico[a] = cos90;
                                    a++;
                            }   else if (x == 180) {
                                    printf("Valor: %lf\nCosseno: %lf\n\n\n\n\n", x, cos180);
                                    historico[a] = cos180;
                                    a++;
                            }   else if (x == 270) {
                                    printf("Valor: %lf\nCosseno: %lf\n\n\n\n\n", x, cos270);
                                    historico[a] = cos270;
                                    a++;
                            }   else if (x == 360) {
                                    printf("Valor: %lf\nCosseno: %lf\n\n\n\n\n", x, cos360);
                                    historico[a] = cos360;
                                    a++;
                            }   else {
                                    printf("Valor: %lf\nCosseno: %lf\n\n\n\n\n", x, cos(x));
                                    historico[a] = cos(x);
                                    a++;
                            }
                                if(a==5){
                                    a = 0;
                                }
                        break;
                    case 9:
                            printf("Insira o valor:\n");
                            scanf("%lf", &l);
                            ln = l;
                                if (ln > 0){
                                    printf("Numero inserido: %d\nSeu logaritmo natural: %lf\n\n\n\n\n", ln, log(ln));
                                    historico[a] = log(ln);
                                    a++;
                                }   else if (ln <= 0){
                                        printf("Indefinido\n\n\n\n\n");
                                }
                                if(a==5){
                                    a = 0;
                                }
                        break;
                    case 10:
                            printf("Insira o valor:\n");
                            scanf("%lf", &fa);
                                p = fa;
                                if (p == 0){
                                    fat = 1;
                                    printf("Numero inserido: %d\nFatorial: %d\n\n\n\n\n", p, fat);
                                    historico[a] = fat;
                                    a++;
                                }
                                else if ((p > 0) && (p < 30)){
                                    fat = fatorial(p);
                                    printf("Numero inserido: %d\nFatorial: %d\n\n\n\n\n", p, fat);
                                    historico[a] = fat;
                                    a++;
                                }   else{
                                        printf("Indefinido\n\n\n\n\n");
                                }
                                if(a==5){
                                    a = 0;
                                }
                        break;
                    case 11:
                        t=0;
                        printf("Os ultimos resultados foram:\n\n");
                            while(t<5){
                                printf("%d) %lf\n\n", b, historico[t]);
                                t++;
                                b++;
                            }
                            b=1;
                        if(a==5){
                            a = 0;
                        }
                        break;
                    case 12:
                        c=0;
                        printf("-----------------//\\OBRIGADO POR USAR A CALCULADORA DO TETEU//\\-----------------\n");
                        break;
                }
            }
    }
}

double soma(double x, double y)
{
    double s = (x+y);
    return s;
}

double subtracao(double x, double y)
{
    double sub = (x-y);
    return sub;
}

double divi(double x, double y)
{
    double d = (x/y);
    return d;
}

double mut(double x, double y)
{
    double m = (x*y);
    return m;
}

int fatorial(int p)
{
    int f = 1, fat;
    for (fat=p; f<p; f++){
        fat = fat*f;
    }
    f=1;
    return fat;
}

double raiz(double x)
{
    double r;
       r = pow(x,0.5);
    return r;
}

double pot(double x, double y)
{
    double po;
    int i;
        po = x;
        for(i=1;i<y;i++){
            po = x*po;
        }
        return po;
}

double pot_neg(double x, double y)
{
    double po, z;
    int i;
        po = 1/x;
        z = (-1)*y;
        for(i=1;i<z;i++){
            po = (1/x)*po;
        }
        return po;
}
