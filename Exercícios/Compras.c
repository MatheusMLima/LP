#include <stdio.h>

double desconto(double tg);
double sem_juros(double tg, double x);
double com_juros(double com_j, double x);
double total(double tg);
double total_juros(double tg, double x);

int main()
{
    double tg, desc, sem_j, juros1, com_j, x;
    int p, a = 1, y;

        printf("Informe o total gasto:\n");
        scanf("%lf", &tg);
        printf("Por favor, escolha a forma de pagamento:\n\n");
        printf("1. A vista com 10 por cento de desconto;\n2. Em 2x sem juros;\n3. Em 3x a 10x com juros de 3 por cento ao mes em compras acima de R$100,00;\n");
        scanf("%d", &p);
        switch (p){
            case 1:
                if (tg > 0.0){
                    desc = desconto(tg);
                    printf("Voce pagara: R$%.2lf\n", desc);
                    break;
                }
            case 2:
                if (tg > 0.0){
                    x = 2.0;
                    sem_j = sem_juros(tg, x);
                    printf("Voce ira pagar 2 parcelas de: R$%.2lf\n", sem_j);
                    printf("Voce ira pagar no total: R$%.2lf\n", tg);
                    break;
                }
            case 3:
                printf("Selecione em quantas vezes ira dividir:\n");
                printf("1. 3x\n2. 4x\n3. 5x\n4. 6x\n5. 7x\n6. 8x\n7. 9x\n8. 10x\n");
                scanf("%d", &y);
                    switch(y){
                        case 1:
                            if (tg > 100.00){
                                x = 3.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 3 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 3.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 3 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf\n", tg );
                                    break;
                            }
                        case 2:
                            if (tg > 100.00){
                                x = 4.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 4 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 4.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 4 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf\n", tg );
                                    break;
                            }
                        case 3:
                            if (tg > 100.00){
                                x = 5.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 5 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 5.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 5 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf\n", tg );
                                    break;
                            }
                        case 4:
                            if (tg > 100.00){
                                x = 6.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 6 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 6.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 6 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf\n", tg );
                                    break;
                            }
                        case 5:
                            if (tg > 100.00){
                                x = 7.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 7 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 7.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 7 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf\n", tg );
                                    break;
                            }
                        case 6:
                            if (tg > 100.00){
                                x = 8.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 8 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 8.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 8 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf\n", tg );
                                    break;
                            }
                        case 7:
                            if (tg > 100.00){
                                x = 9.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 9 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 9.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 9 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf", tg );
                                    break;
                            }
                        case 8:
                            if (tg > 100.00){
                                x = 10.0;
                                com_j = total_juros(tg, x);
                                juros1 = com_juros(com_j, x);
                                printf("Voce ira pagar 10 parcelas de: R$%.2lf\n", juros1);
                                printf("Voce ira pagar no total: R$%.2lf\n", com_j);
                                break;
                            }   else if ((tg < 100.00) && (tg > 0.00)){
                                    x = 10.0;
                                    sem_j = sem_juros(tg, x);
                                    printf("Voce ira pagar 10 parcelas de: R$%.2lf\n", sem_j);
                                    printf("Voce ira pagar no total: R$%.2lf\n", tg );
                                    break;
                            }
                        default:
                            printf("Numero invalido!!");
                            break;
                    }
                break;
            default:
                printf("Numero invalido!!");
                break;
        }
}

double desconto(double tg)
{
    double desc, d;

    d = tg*0.1;
    desc = tg-d;
    return desc;
}

double sem_juros(double tg, double x)
{
    double sem_j;
    
    sem_j = tg/x;
    return sem_j;
}

double total_juros(double tg, double x)
{
    double com_j, t, tt;
    t = tg*0.03;
    tt = t*x;
    com_j = tg + tt;
    return com_j;
}

double com_juros(double com_j, double x)
{
    double juros1;

    juros1 = com_j/x;
    return juros1;
    
}