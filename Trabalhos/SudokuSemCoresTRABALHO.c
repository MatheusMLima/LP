#include <stdio.h>

#define NULL ((void*)0)

void tabuleiro(int sudoku[6][6], int i, int j, int *ptr[36]);
void tabuleiro2(int sudoku[6][6], int i, int j, int *ptr[36]);
void menu();
void menu1();
void menu2();
void regras();
void mostrartabuleiro(int sudoku[6][6], int i, int j);
void escolhendo(int c, int sudoku[6][6], int l, int *ptr[36], int i, char lin, char col, char sudoku1[6][6]);
int ver_e_fim(int i, int l, int k, int z, int sudoku[6][6], int aux, int cont, int final, int j, int a);

int main()
{
    char d, lin, col, sudoku1[6][6];
    int sudoku[6][6], i, j, a=1, l, c, *ptr[36], k, cont=0, z, aux=0, final, rec;
    while(a>0){
        menu();
        scanf("%s", &d);
    switch(d){
        case '1':
            while(a>0){
                menu1();
                scanf("%s", &d);
                switch(d){
                    case '1':
                        regras();
                        break;
                    default:
                        tabuleiro(sudoku,i,j,ptr);
                        while(a>0){
                            mostrartabuleiro(sudoku,i,j);
                            escolhendo(c,sudoku,l,ptr,i,lin,col,sudoku1);
                            rec = ver_e_fim(i,l,k,z,sudoku,aux,cont,final,j,a);
                            a = rec;
                        }
                        break;
                }
            }
        break;
        case '2':
            while(a>0){
                menu2();
                scanf("%s", &d);
                switch(d){
                    case '1':
                        regras();
                        break;
                    default:
                        tabuleiro2(sudoku,i,j,ptr);
                        printf("---------------------------------------------SUDOKU INICIADO!---------------------------------------------\n");
                        while(a>0){
                            mostrartabuleiro(sudoku,i,j);
                            escolhendo(c,sudoku,l,ptr,i,lin,col,sudoku1);
                            rec = ver_e_fim(i,l,k,z,sudoku,aux,cont,final,j,a);
                            a = rec;
                        }
                        break;
                }
            }
        break;
        }
    }
}

void tabuleiro(int sudoku[6][6], int i, int j, int *ptr[36])
{
    int k;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){          //*atribui espaço vazio para todas as casas da matriz para que não aparece nada no printf
            sudoku[i][j] = NULL;
        }
    }
    sudoku[0][2] = 4;
    sudoku[0][3] = 2;
    sudoku[0][4] = 3;
    sudoku[1][1] = 2;
    sudoku[1][4] = 1;
    sudoku[2][0] = 2;
    sudoku[3][0] = 3;
    sudoku[2][5] = 3;
    sudoku[3][5] = 1;
    sudoku[3][3] = 4;
    sudoku[4][1] = 5;
    sudoku[5][1] = 3;
    sudoku[5][2] = 6;
    sudoku[5][3] = 1;
    sudoku[4][4] = 4;
    k=0;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(sudoku[i][j]!=NULL){
                ptr[k] = &sudoku[i][j];   //*atribui o endereço de cada posição fixa em um ponteiro vetor
                k++;
            } else {
                ptr[k] = NULL;
                k++;
            }
        }
    }
    return tabuleiro;
}

void tabuleiro2(int sudoku[6][6], int i, int j, int *ptr[36])
{
    int k, l, c, a=1;
    char lin, col, sudoku1[6][6];
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            sudoku[i][j] = NULL;
        }
    }
    printf("CUIDADO, DEPOIS QUE ESCOLHER E COMECAR O JOGO, OS NUMEROS FIXOS NAO PODERAO SER TROCADOS!!\n\n\n");
    printf("Escolha os numeros fixos do seu sudoku!!\n");
    while(a==1){
        mostrartabuleiro(sudoku,i,j);
        printf("Escolha uma linha de 1 a 6:\n");    //*escolhe a linha do sudoku
        scanf("%s", &lin);
        l = lin-'1';
        while((l<0) || (l>5)){
            printf("\n\nValor invalido! Por favor, digite outro!\n");
            scanf("%s", &lin);
            l = lin-'1';
        }
        printf("\n\nEscolha uma coluna de 1 a 6:\n");
        scanf("%s", &col);
        c = col-'1';                                            //*escolhe a coluna do sudoku
        while((c<0) || (c>5)){
            printf("\n\nValor invalido! Por favor, digite outro!\n");
            scanf("%s", &col);
            c = col-'1';
        }
        printf("\n\nInsira o numero desejado:\n");
        scanf("%s", &sudoku1[l][c]);
        while(sudoku1[l][c]=='0'){                           //* da um valor fixo para aquela posição
            printf("\n\nValor invalido! Por favor, digite outro!\n");
            scanf("%s", &sudoku1[l][c]);
        }
        sudoku[l][c] = sudoku1[l][c]-'1';
        sudoku[l][c] += 1;
        while((sudoku[l][c]>=7) || (sudoku[l][c]<=0)){
            printf("\n\nValor invalido! Por favor, digite outro!\n");
            scanf("%s", &sudoku1[l][c]);
            sudoku[l][c] = sudoku1[l][c]-'1';
            sudoku[l][c] += 1;
        }
        mostrartabuleiro(sudoku,i,j);
        printf("Deseja acrescentar outro numero fixo?\n(1)Sim\n(2)Nao\n");
        scanf("%d", &a);
        while(a>2 || a<1){
            printf("Valor invalido! Por favor, escolha de novo!\n");
            printf("Deseja acrescentar outro numero fixo?\n(1)Sim\n(2)Nao\n");
            scanf("%d", &a);
        }
    }
    k=0;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(sudoku[i][j]!=NULL){
                ptr[k] = &sudoku[i][j];
                k++;                       //*atribui o endereço de cada posição fixa inserida em um ponteiro vetor
            } else {
                ptr[k] = NULL;
                k++;
            }
        }
    }
    return tabuleiro;
}

void menu()
{
    printf("--------------------------------------------BEM VINDO AO SUDOKU!--------------------------------------------\n\n\n\n");
    printf("Aperte 1 para iniciar o Sudoku com numeros dados pelo criador!\n\n");
    printf("Aperte 2 para criar seu proprio Sudoku!\n\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    return menu;
}

void menu1()
{
    printf("----------------------------------------BEM VINDO AO TETEU'S SUDOKU!----------------------------------------\n\n\n\n");
    printf("Aperte 1 para ver as regras!\n\n\n\n");
    printf("-------------------------------------APERTE QUALQUER TECLA PARA INICIAR-------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    return menu;
}

void menu2()
{
    printf("------------------------------------------BEM VINDO AO SEU SUDOKU!------------------------------------------\n\n\n\n");
    printf("Aperte 1 para ver as regras!\n\n\n\n");
    printf("-------------------------------------APERTE QUALQUER TECLA PARA INICIAR-------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    return menu;
}

void regras()
{
    printf("\n\n\n1. Voce NAO pode mudar os numeros fixos.\n");
    printf("2. Voce devera preencher as linhas, colunas e agrupamentos de 2x3 de forma que nao tenha numeros iguais.\n");
    printf("3. Caso coloque um numero errado, voce podera corrigir.\n");
    printf("4. A primeira linha e coluna comeca em 1 e termina em 6.\n");
    printf("5. O jogo aceita numeros decimais porem apenas sera considerado o seu valor inteiro.\n");
    printf("6. Do mesmo jeito, numeros de 10 para cima serao aceitos, porem apenas o primeiro numero sera considerado.\n");
    printf("***EXEMPLO*** Valor inserido: 145, o valor considerado sera apenas 1.\n");
    printf("7. Vence se conseguir completar toda a tabela cumprindo os requisitos da regra 2.\n\n\n\n\n");
    return regras;
}

void mostrartabuleiro(int sudoku[6][6], int i, int j)
{
    printf("\n\n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(sudoku[i][j]==NULL){
                printf("|   |");
                if(j==2){
                    printf("|---|");
                }
            } else {
                printf("| %d |", sudoku[i][j]);
                if(j==2){
                    printf("|---|");
                }
            }
        }
        if(i==1 || i==3){
            printf("\n-----------------------------------");
        }
    printf("\n");
    }
    printf("\n\n");
    return mostrartabuleiro;
}

void escolhendo(int c, int sudoku[6][6], int l, int *ptr[36], int i, char lin, char col, char sudoku1[6][6])
{
    printf("Escolha uma linha de 1 a 6:\n");
    scanf("%s", &lin);
    l = lin-'1';
    while((l<0) || (l>5)){
        printf("\n\nValor invalido! Por favor, digite outro!\n");
        scanf("%s", &lin);
        l = lin-'1';
    }
    printf("\n\nEscolha uma coluna de 1 a 6:\n");
    scanf("%s", &col);
    c = col-'1';
    while((c<0) || (c>5)){
        printf("\n\nValor invalido! Por favor, digite outro!\n");
        scanf("%s", &col);
        c = col-'1';
    }
    for(i=0;i<36;i++){
        if(&sudoku[l][c]==ptr[i]){                            //o for ira percorrer todo o ponteiro vetor para ver se tem um endereço igual
            printf("\n\n****PARA DE TENTAR ROUBAR****\n\n");   //ao daquela posição, se tiver, não deixará o usuário colocar um valor
            break;
        }
    }
    if(&sudoku[l][c]==ptr[i]){
        return escolhendo;
    } else {
        printf("\n\nInsira o numero desejado:\n");
        scanf("%s", &sudoku1[l][c]);
        while(sudoku1[l][c]=='0'){
            printf("\n\nValor invalido! Por favor, digite outro!\n");
            scanf("%s", &sudoku1[l][c]);
        }
        sudoku[l][c] = sudoku1[l][c]-'1';
        sudoku[l][c] += 1;
            while((sudoku[l][c]>=7) || (sudoku[l][c]<=0)){
                printf("\n\nValor invalido! Por favor, digite outro!\n");
                scanf("%s", &sudoku1[l][c]);
                sudoku[l][c] = sudoku1[l][c]-'1';
                sudoku[l][c] += 1;
                return escolhendo;
            }

    }
    return escolhendo;
}

int ver_e_fim(int i, int l, int k, int z, int sudoku[6][6], int aux, int cont, int final, int j, int a)
{
    for(i=0;i<6;i++){              //verifica as linhas
        for(k=0;k<6;k++){
            for(j=0;j<6;j++){
                if(sudoku[i][k]!=NULL){
                    if(sudoku[i][k]!=sudoku[i][j]){   //cada casa da matriz ira comparar com casa da linha em toda a matriz
                        cont++;
                    } else {
                        aux++;
                    }
                }
            }
        }
    }
    for(i=0;i<6;i++){
        for(k=0;k<6;k++){         //verifica as colunas
            for(j=0;j<6;j++){
                if(sudoku[k][i]!=NULL){
                    if(sudoku[k][i]!=sudoku[j][i]){   //cada casa da matriz ira comparar com casa da coluna em toda a matriz
                        cont++;
                    } else {
                        aux++;
                    }
                }
            }
        }
    }
    for(i=0;i<3;i++){
        for(z=0;z<2;z++){         //verifica o 1 quadrante
            for(k=0;k<2;k++){
                for(j=0;j<3;j++){
                    if(sudoku[z][i]!=NULL){     //cada casa do quadrante irá ser comparado com as outras
                        if(sudoku[z][i]!=sudoku[k][j]){
                            cont++;
                        } else {
                            aux++;
                        }
                    }
                }
            }
        }
    }
    for(i=3;i<6;i++){
        for(z=0;z<2;z++){
            for(k=0;k<2;k++){     //verifica o 2 quadrante
                for(j=3;j<6;j++){
                    if(sudoku[z][i]!=NULL){    //cada casa do quadrante irá ser comparado com as outras
                        if(sudoku[z][i]!=sudoku[k][j]){
                            cont++;
                        } else {
                            aux++;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<3;i++){
        for(z=2;z<4;z++){
            for(k=2;k<4;k++){      //verifica o 3 quadrante
                for(j=0;j<3;j++){
                    if(sudoku[z][i]!=NULL){      //cada casa do quadrante irá ser comparado com as outras
                        if(sudoku[z][i]!=sudoku[k][j]){
                            cont++;
                        } else {
                            aux++;
                        }
                    }
                }
            }
        }
    }
    for(i=3;i<6;i++){
        for(z=2;z<4;z++){            //verifica o 4 quadrante
            for(k=2;k<4;k++){
                for(j=3;j<6;j++){
                    if(sudoku[z][i]!=NULL){      //cada casa do quadrante irá ser comparado com as outras
                        if(sudoku[z][i]!=sudoku[k][j]){
                            cont++;
                        } else {
                            aux++;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<3;i++){
        for(z=4;z<6;z++){             //verifica o 5 quadrante
            for(k=4;k<6;k++){
                for(j=0;j<3;j++){
                    if(sudoku[z][i]!=NULL){        //cada casa do quadrante irá ser comparado com as outras
                        if(sudoku[z][i]!=sudoku[k][j]){
                            cont++;
                        } else {
                            aux++;
                        }
                    }
                }
            }
        }
    }
    for(i=3;i<6;i++){
        for(z=4;z<6;z++){        //verifica o 6 quadrante
            for(k=4;k<6;k++){
                for(j=3;j<6;j++){        //cada casa do quadrante irá ser comparado com as outras
                    if(sudoku[z][i]!=NULL){
                        if(sudoku[z][i]!=sudoku[k][j]){
                            cont++;
                        } else {
                            aux++;
                        }
                    }
                }
            }
        }
    }
    final = cont-aux;     //no final, o cont terá feito tantas vericações e o aux também
    if(final == 432){      //e a subtração de cont por aux dará 432, se todos os valores estiverem nas suas posições corretas
        a = 0;
        mostrartabuleiro(sudoku,i,j);
        printf("\n\n\n--------------------------PARABENS, VOCE CONSEGUIU CONCLUIR O SUDOKU!!!!--------------------------\n\n\n");
        printf("\n\n\n----------------------------------DESENVOLVIDO POR MATHEUS LIMA!----------------------------------\n\n\n");
        return a;
    } else {
        cont = 0;
        aux = 0;
        return ver_e_fim;
    }
}
