#include <stdio.h>
#include <string.h>

#define NULL ((void*)0)           

struct Data_Lancamento{
        int ano, dia;
        char mes[20];
};

struct Filmes{
    int codigo_filme, duracao_min, restricao;
    char nome_filme[50], genero[50], diretor[50], atores_principais[200], sinopse[1600];
    struct Data_Lancamento datas;
};

void Catalogo(struct Filmes filme[1000],struct Data_Lancamento datas);
void Filmes_generos(struct Filmes filme[1000],struct Data_Lancamento datas, char genero[15], int idades);
void Filmes_todos(struct Filmes filme[1000],struct Data_Lancamento datas, int idades);
void Filmes_nome(struct Filmes filme[1000],struct Data_Lancamento datas, int idades);
void Filmes_ordem(struct Filmes filme[1000],struct Data_Lancamento datas);
void cadastrar_filme(struct Filmes filme[1000],struct Data_Lancamento datas);
void alterar_filme(struct Filmes filme[1000],struct Data_Lancamento datas);
void filmess(struct Filmes filme[1000],struct Data_Lancamento datas, int i);
void remover_filme(struct Filmes filme[1000],struct Data_Lancamento datas);
void transformar(struct Filmes filme[1000],struct Data_Lancamento datas);
void menu(char *n);
void nome_usuario(char *nome[20]);
void idade_usuario(double *idade);
void menu1(char *n, char *nome[20]);
void menu2(char *n);
void menu3(char *n);
void menu4(char *n, char *nome[20]);
void fim(char nome[20]);
void regras();
void muda1(char nome1[100]);
void muda(char nome[100]);
void muda2(char genero1[15]);

int main()
{
    struct Filmes filme[1000];
    struct Data_Lancamento datas;
    char n, senha[20], nome[20], genero[15], a='4', aux[5];
    int i, idades, cru=0;
    double idade;
    Catalogo(filme,datas);
    while(a!='3'){
        inicio:
        menu(&n);
        switch(n){
            case '1':
                nome_usuario(&nome);
                idade_usuario(&idade);
                idades = idade;
                if(idades<8){
                    printf("Voce nao tem idade suficiente para criar um usuario!\n");
                    break;
                }
                while(a!='3'){
                    menu1(&n,&nome);
                    switch(n){
                        case '1':
                            menu2(&n);
                            switch(n){
                                case '1':
                                    menu3(&n);
                                    switch(n){
                                        case '1':
                                            strcpy(genero, "acao");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                        case '2':
                                            strcpy(genero, "terror");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                        case '3':
                                            strcpy(genero, "animacao");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                        case '4':
                                            strcpy(genero, "sci-fi");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                        case '5':
                                            strcpy(genero, "comedia");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                        case '6':
                                            strcpy(genero, "guerra");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                        case '7':
                                            strcpy(genero, "super heroi");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                        case '8':
                                            strcpy(genero, "drama");
                                            Filmes_generos(filme,datas,genero,idades);
                                        break;
                                }
                                break;
                                case '2':
                                    Filmes_nome(filme,datas,idades);
                                break;
                                case '3':
                                break;
                            }
                        break;
                        case '2':
                            Filmes_ordem(filme,datas);
                            Filmes_todos(filme,datas,idades);
                        break;
                        case '3':
                            goto inicio;
                        break;
                    }
                }
            break;
            case '2':
                nome_usuario(&nome);
                printf("Insira a senha de administrador:\n");
                gets(senha);
                setbuf(stdin,NULL);
                if(strcmp(senha,"lilian")==0){
                    entrar:
                    menu4(&n,&nome);
                    switch(n){
                        case '1':
                            cadastrar_filme(filme,datas);
                            goto entrar;
                        break;
                        case '2':
                            alterar_filme(filme,datas);
                            goto entrar;
                        break;
                        case '3':
                            remover_filme(filme,datas);
                            goto entrar;
                        break;
                        case '4':
                        break;
                        case '5':
                            regras();
                            goto entrar;
                        break;
                    }
                } else {
                    for(i=0;i<4;i++){
                        if(strcmp(senha,"lilian")!=0){
                            printf("Senha incorreta! %d tentativa(s) restante(s)!\n", (5-(i+1)));
                            gets(senha);
                            setbuf(stdin,NULL);
                            cru += 2;
                        } else {
                            break;
                        }
                    }
                    if(cru!=10){
                        cru = 0;
                        goto entrar;
                    } else if(cru==10){
                        printf("Tente novamente mais tarde!\n");
                        exit(0);
                    }
                }
            break;
            case '3':
                fim(nome);
            break;
        }
    }
}

void menu(char *n)
{
    printf("                               Seja bem vindo a Netflix!                               \n\n\n");
    printf("Por favor, escolha o tipo da sua conta:\n\n");
    printf("1) Usuario\n2) Administrador\n3) Sair\n");
    scanf(" %s", &*n);
    setbuf(stdin,NULL);
    while(*n!='1' && *n!='2' && *n!='3'){
        printf("                               Seja bem vindo a Netflix!                               \n\n\n");
        printf("Por favor, escolha o tipo da sua conta:\n\n");
        printf("1) Usuario\n2) Administrador\n3) Sair\n");
        scanf(" %s", &*n);
        setbuf(stdin,NULL);
    }
    return n;
}

void regras()
{
    printf("                               REGRAS DO ADMINISTRADOR!                               \n\n\n");
    printf("1) Atencao ao adicionar um filme, lembre-se sempre de colocar a primeira letra do genero maiuscula\n"
           "2) Os generos ja estao definidos, nao ha como adicionar novos generos\n"
           "3) Cuidado para nao deixar espacos apos os nomes, isso dificultara a vida do usuario\n");
    return regras;
}

void nome_usuario(char *nome[20])
{
    printf("Insira seu nome:\n");
    gets(nome);
    setbuf(stdin,NULL);
    return nome;
}

void idade_usuario(double *idade)
{
    printf("Insira sua idade:\n");
    scanf("%lf", &*idade);
    setbuf(stdin,NULL);
    return idade;
}

void menu1(char *n, char *nome[20])
{
    printf("                               Seja bem vindo, %s!                               \n\n\n", nome);
    printf("1) Buscar filme\n2) Mostrar todos os filmes em catalogo(Por ano de lancamento)\n3) Sair\n");
    scanf(" %s", &*n);
    setbuf(stdin,NULL);
    while(*n!='1' && *n!='2' && *n!='3'){
        printf("                               Seja bem vindo, %s!                               \n\n\n", nome);
        printf("1) Buscar filme\n2) Mostrar todos os filmes em catalogo(Por ano de lancamento)\n3) Sair\n");
        scanf(" %s", &*n);
        setbuf(stdin,NULL);
    }
    return n;
}

void menu2(char *n)
{
    printf("                               Buscar filmes                               \n\n\n");
    printf("1) Pesquisar filmes por generos\n2) Pesquisar um filme pelo nome\n3) Sair\n");
    scanf(" %s", &*n);
    setbuf(stdin,NULL);
    while(*n!='1' && *n!='2' && *n!='3'){
        printf("                               Buscar filmes                               \n\n\n");
        printf("1) Pesquisar filmes por generos\n2) Pesquisar um filme pelo nome\n3) Sair\n");
        scanf(" %s", &*n);
        setbuf(stdin,NULL);
    }
    return n;
}

void menu3(char *n)
{
    printf("                               Pesquisa por generos                               \n\n\n");
    printf("1) Acao\n2) Terror\n3) Animacao\n4) Sci-Fi\n5) Comedia\n6) Guerra\n7) Super Heroi\n8) Drama\n");
    scanf(" %s", &*n);
    setbuf(stdin,NULL);
    while(*n!='1' && *n!='2' && *n!='3' && *n!='4' && *n!='5' && *n!='6' && *n!='7' && *n!='8'){
        printf("                               Pesquisa por generos                               \n\n\n");
        printf("1) Acao\n2) Terror\n3) Animacao\n4) Sci-Fi\n5) Comedia\n6) Guerra\n7) Super Heroi\n8) Drama\n");
        scanf(" %s", &*n);
        setbuf(stdin,NULL);
    }
}

void menu4(char *n, char *nome[20])
{
    printf("                               Seja bem vindo, %s!                               \n\n\n", nome);
    printf("1) Cadastrar um filme\n2) Alterar dados de um filme\n3) Remover um filme\n4) Sair\n\n\n5)REGRAS DO ADMINISTRADOR --- IMPORTANTE ---\n\n");
    scanf(" %s", &*n);
    setbuf(stdin,NULL);
    while(*n!='1' && *n!='2' && *n!='3' && *n!='4' && *n!='5'){
        printf("                               Seja bem vindo, %s!                               \n\n\n", nome);
        printf("1) Cadastrar um filme\n2) Alterar dados de um filme\n3) Remover um filme\n4) Sair\n\n\n5)REGRAS DO ADMINISTRADOR --- IMPORTANTE ---\n\n");
        scanf(" %s", &*n);
        setbuf(stdin,NULL);
    }
    return n;
}

void fim(char nome[20])
{
    printf("Obrigado por utilizar nosso servico de streaming, volte sempre %s!\n", nome);
    exit(0);
}

void Catalogo(struct Filmes filme[1000],struct Data_Lancamento datas)
{
    int i;
    for(i=0;i<1000;i++){
        filme[i].codigo_filme = i+1;
        strcpy(filme[i].nome_filme," ");
        strcpy(filme[i].genero," ");
        strcpy(filme[i].diretor," ");
        strcpy(filme[i].atores_principais," ");
        strcpy(filme[i].sinopse," ");
        filme[i].duracao_min = NULL;
        filme[i].datas.dia = NULL;
        filme[i].datas.ano = NULL;
        filme[i].restricao = NULL;
        strcpy(filme[i].datas.mes," ");

    }
    strcpy(filme[0].nome_filme, "Jogador Numero 1");
    strcpy(filme[0].genero, "Sci-Fi");
    strcpy(filme[0].diretor, "Steven Spielberg");
    strcpy(filme[0].atores_principais, "Tye Sheridan, Olivia Cooke, Ben Mendelsohn, Lena Waithe, Simon Pegg, Mark Rylance, T.J. Miller, Hannah John-Kamen");
    strcpy(filme[0].sinopse, "Num futuro distopico, em 2044, Wade Watts (Tye Sheridan), como o resto da humanidade, prefere a realidade virtual do jogo OASIS ao mundo real.\n"
                             "Quando o criador do jogo, o excentrico James Halliday (Mark Rylance) morre, os jogadores devem descobrir a chave de um quebra-cabeca diabolico para\n"
                             "conquistar sua fortuna inestimavel. Para vencer, porem, Watts tera de abandonar a existencia virtual e ceder a uma vida de amor e realidade da qual sempre tentou fugir.");
    filme[0].duracao_min = 140;
    filme[0].datas.dia = 29;
    filme[0].datas.ano = 2018;
    filme[0].restricao = 12;
    strcpy(filme[0].datas.mes, "Marco");
    strcpy(filme[1].nome_filme, "Na Natureza Selvagem");
    strcpy(filme[1].genero, "Drama");
    strcpy(filme[1].diretor, "Sean Penn");
    strcpy(filme[1].atores_principais, "Emile Hirsch, Marcia Gay Harden, William Hurt, Jena Malone, Brian Dierker, Catherine Keener, Vince Vaughn, Kristen Stewart");
    strcpy(filme[1].sinopse, "Inicio da decada de 90. Christopher McCandless (Emile Hirsch) eh um jovem recem-formado, que decide viajar sem rumo pelos Estados Unidos em busca da liberdade.\n"
                             "Durante sua jornada pela Dakota do Sul, Arizona e California ele conhece pessoas que mudam sua vida, assim como sua presenca tambem modifica as delas.\n"
                             "Ate que, apos dois anos na estrada, Christopher decide fazer a maior das viagens e partir rumo ao Alasca.");
    filme[1].duracao_min = 148;
    filme[1].datas.dia = 14;
    filme[1].datas.ano = 2008;
    filme[1].restricao = 12;
    strcpy(filme[1].datas.mes, "Marco");
    strcpy(filme[2].nome_filme, "De volta para o Futuro");
    strcpy(filme[2].genero, "Sci-Fi");
    strcpy(filme[2].diretor, "Robert Zemeckis");
    strcpy(filme[2].atores_principais, "Michael J. Fox, Christopher Lloyd, Lea Thompson, Crispin Glover, Thomas F. Wilson, Marc McClure, Wendie Jo Sperber, George DiCenzo");
    strcpy(filme[2].sinopse, "Um jovem (Michael J. Fox) aciona acidentalmente uma maquina do tempo construida por um cientista (Christopher Lloyd) em um Delorean, retornando aos anos 50.\n"
                             "La conhece sua mae (Lea Thompson), antes ainda do casamento com seu pai, que fica apaixonada por ele.\n"
                             "Tal paixao poe em risco sua propria existencia, pois alteraria todo o futuro, forcando-o a servir de cupido entre seus pais.");
    filme[2].duracao_min = 116;
    filme[2].datas.dia = 25;
    filme[2].datas.ano = 1985;
    filme[2].restricao = 0;
    strcpy(filme[2].datas.mes, "Dezembro");
    strcpy(filme[3].nome_filme, "Marley & Eu");
    strcpy(filme[3].genero, "Drama");
    strcpy(filme[3].diretor, "David Frankel");
    strcpy(filme[3].atores_principais, "Owen Wilson, Jennifer Aniston, Eric Daen, Haley Bennett, Alan Arkin, Nathan Gamble, Clarke Peters, Ana Ayora");
    strcpy(filme[3].sinopse, "John (Owen Wilson) e Jennifer Grogan (Jennifer Aniston) casaram-se recentemente e decidiram comecar nova vida em West Palm Beach, na Florida.\n"
                             "La, eles trabalham em jornais concorrentes, compram um imovel e enfrentam os desafios de uma vida de casal.\n"
                             "Indeciso sobre sua capacidade em ser pai, John busca o conselho de seu colega Sebastian (Eric Dane), que sugere que compre um cachorro para a esposa.\n"
                             "John aceita a sugestao e adota Marley, um labrador de 5 kg que logo se transforma em um grande cachorro de 45 kg, o que torna a casa deles um caos.");
    filme[3].duracao_min = 115;
    filme[3].datas.dia = 25;
    filme[3].datas.ano = 2008;
    filme[3].restricao = 10;
    strcpy(filme[3].datas.mes, "Dezembro");
    strcpy(filme[4].nome_filme, "Guardioes da Galaxia");
    strcpy(filme[4].genero, "Super Heroi");
    strcpy(filme[4].diretor, "James Gunn");
    strcpy(filme[4].atores_principais, "Chris Pratt, Zoe Saldana, Dave Bautista, Lee Pace, Benicio Del Toro, Karen Gillan, Glenn Close, John C. Reilly");
    strcpy(filme[4].sinopse, "Peter Quill (Chris Pratt) foi abduzido da Terra quando ainda era crianca. Adulto, fez carreira como saqueador e ganhou o nome de Senhor das Estrelas.\n"
                             "Quando rouba uma esfera, na qual o poderoso vilao Ronan, da raca kree, esta interessado, passa a ser procurado por varios cacadores de recompensas.\n"
                             "Para escapar do perigo, Quill une forcas com quatro personagens fora do sistema: Groot, uma arvore humanoide (Vin Diesel),\n"
                             "a sombria e perigosa Gamora (Zoe Saldana), o guaxinim rapido no gatilho Rocket Racoon (Bradley Cooper) e o vingativo Drax, o Destruidor (Dave Bautista).\n"
                             "Mas o Senhor das Estrelas descobre que a esfera roubada possui um poder capaz de mudar os rumos do universo,\n"
                             "e logo o grupo devera proteger o objeto para salvar o futuro da galaxia.");
    filme[4].duracao_min = 122;
    filme[4].datas.dia = 31;
    filme[4].datas.ano = 2014;
    filme[4].restricao = 13;
    strcpy(filme[4].datas.mes, "Julho");
    strcpy(filme[5].nome_filme, "Vingadores Ultimato");
    strcpy(filme[5].genero, "Super Heroi");
    strcpy(filme[5].diretor, "Anthony Russo, Joe Russo");
    strcpy(filme[5].atores_principais, "Robert Downey Jr., Chris Evans, Mark Ruffalo, Chris Hemsworth, Scarlett Johansson, Jeremy Renner, Josh Brolin, Paul Rudd");
    strcpy(filme[5].sinopse, "Apos Thanos eliminar metade das criaturas vivas, os Vingadores precisam lidar com a dor da perda de amigos e seus entes queridos.\n"
                             "Com Tony Stark (Robert Downey Jr.) vagando perdido no espaco sem agua nem comida,\n"
                             "Steve Rogers (Chris Evans) e Natasha Romanov (Scarlett Johansson) precisam liderar a resistencia contra o tita louco.");
    filme[5].duracao_min = 182;
    filme[5].datas.dia = 25;
    filme[5].datas.ano = 2019;
    filme[5].restricao = 12;
    strcpy(filme[5].datas.mes, "Abril");
    strcpy(filme[6].nome_filme, "O Resgate do Soldado Ryan");
    strcpy(filme[6].genero, "Guerra");
    strcpy(filme[6].diretor, "Steven Spielberg");
    strcpy(filme[6].atores_principais, "Ryan Hurst, Tom Hanks, Tom Sizemore, Edward Burns, Barry Pepper, Adam Goldberg, Vin Diesel, Matt Damon");
    strcpy(filme[6].sinopse, "Ao desembarcar na Normandia, no dia 6 de junho de 1944, capitao Miller (Tom Hanks) recebe a missao de comandar um grupo do segundo batalhao para o resgate do soldado James Ryan,\n"
                             "cacula de quatro irmaos, dentre os quais tres morreram em combate. Por ordens do chefe George C. Marshall,\n"
                             "eles precisam procurar o soldado e garantir o seu retorno, com vida, para casa.");
    filme[6].duracao_min = 169;
    filme[6].datas.dia = 5;
    filme[6].datas.ano = 1999;
    filme[6].restricao = 14;
    strcpy(filme[6].datas.mes, "Marco");
    strcpy(filme[7].nome_filme, "Coracoes de Ferro");
    strcpy(filme[7].genero, "Guerra");
    strcpy(filme[7].diretor, "David Ayer");
    strcpy(filme[7].atores_principais, "Brad Pitt, Shia LaBeouf, Logan Lerman, Michael Pena, Jon Bernthal, Jim Parrack, Brad William Henke, Jason Isaacs");
    strcpy(filme[7].sinopse, "Durante o final da Segunda Guerra Mundial, um grupo de cinco soldados americanos eh encarregado de atacar os nazistas dentro da propria Alemanha.\n"
                             "Apesar de estarem em quantidade inferior e terem poucas armas, eles sao liderados pelo enfurecido Wardaddy (Brad Pitt), sargento que pretende leva-los a vitoria,\n"
                             "enquanto ensina o novato Norman (Logan Lerman) a lutar.");
    filme[7].duracao_min = 134;
    filme[7].datas.dia = 5;
    filme[7].datas.ano = 2015;
    filme[7].restricao = 16;
    strcpy(filme[7].datas.mes, "Fevereiro");
    strcpy(filme[8].nome_filme, "O Rei Leao");
    strcpy(filme[8].genero, "Animacao");
    strcpy(filme[8].diretor, "Roger Allers, Rob Minkoff");
    strcpy(filme[8].atores_principais, "Matthew Broderick, James Earl Jones, Madge Sinclair, Rowan Atkinson, Jeremy Irons, Nathan Lane, Whoopi Goldberg, Moira Kelly");
    strcpy(filme[8].sinopse, "Mufasa (voz de James Earl Jones), o Rei Leao, e a rainha Sarabi (voz de Madge Sinclair) apresentam ao reino o herdeiro do trono, Simba (voz de Matthew Broderick).\n"
                             "O recem-nascido recebe a bencao do sabio babuino Rafiki (voz de Robert Guillaume), mas ao crescer eh envolvido nas artimanhas de seu tio Scar (voz de Jeremy Irons),\n"
                             "o invejoso e maquiavelico irmao de Mufasa, que planeja livrar-se do sobrinho e herdar o trono");
    filme[8].duracao_min = 89;
    filme[8].datas.dia = 8;
    filme[8].datas.ano = 1994;
    filme[8].restricao = 0;
    strcpy(filme[8].datas.mes, "Julho");
    strcpy(filme[9].nome_filme, "Irmao Urso");
    strcpy(filme[9].genero, "Animacao");
    strcpy(filme[9].diretor, "Robert Walker, Aaron Blaise");
    strcpy(filme[9].atores_principais, "Joaquim Phoenix, Jeremy Suarez, Rick Moranis, Dave Thomas, D.B. Sweeney, Michael Clarke Duncan, Harold Gould, Estelle Harris");
    strcpy(filme[9].sinopse, "Em busca de vinganca por seu irmao ter sido morto por um urso, o indio Kenai acaba sendo amaldicoado pelos espiritos da floresta e eh transformado em um urso.\n"
                             "Obrigado a viver sob a nova pele, ele comeca a ver a realidade sob a otica dos animais.\n"
                             "Logo faz amizade com outro urso, Koda, mas se ve em apuros quando seu proprio irmao comeca a caca-lo");
    filme[9].duracao_min = 85;
    filme[9].datas.dia = 12;
    filme[9].datas.ano = 2003;
    filme[9].restricao = 0;
    strcpy(filme[9].datas.mes, "Dezembro");
    strcpy(filme[10].nome_filme, "Curtindo a Vida Adoidado");
    strcpy(filme[10].genero, "Comedia");
    strcpy(filme[10].diretor, "John Hughes");
    strcpy(filme[10].atores_principais, "Matthew Broderick, Alan Ruck, Mia Sara, Jeffrey Jones, Jennifer Grey, Cindy Pickett, Edie McClurg, Charlie Sheen");
    strcpy(filme[10].sinopse, "No ultimo semestre do curso do colegio, Ferris Bueller (Matthew Broderick)\n"
                              "sente um incontrolavel desejo de matar a aula e planeja um grande programa na cidade com sua namorada (Mia Sara), seu melhor amigo (Alan Ruck) e uma Ferrari.\n"
                              "So que para poder realizar seu desejo ele precisa escapar do diretor do colegio (Jeffrey Jones) e de sua irma (Jennifer Grey).");
    filme[10].duracao_min = 103;
    filme[10].datas.dia = 19;
    filme[10].datas.ano = 1986;
    filme[10].restricao = 0;
    strcpy(filme[10].datas.mes, "Dezembro");
    strcpy(filme[11].nome_filme, "Todo Mundo em Panico");
    strcpy(filme[11].genero, "Comedia");
    strcpy(filme[11].diretor, "Keenen Ivory Wayans");
    strcpy(filme[11].atores_principais, "Anna Faris, Shawn Wayans, Marlon Wayans, Shannon Elizabeth, Kurt Fuller, Carmen Electra, Jon Abrahams, Regina Hall");
    strcpy(filme[11].sinopse, "Das mentes dos criadores do seriado da TV americana 'In living color' surge o primeiro thriller-comedia,\n"
                              "em que adolescentes apavorados fugindo de maniacos assassinos sao o pretexto para uma serie de piadas envolvendo todos os recentes filme de terror,\n"
                              "da serie 'Panico' ate 'O sexto sentido', passando ainda por outros grandes sucessos do cinema, como 'Matrix' e 'Os suspeitos'.");
    filme[11].duracao_min = 88;
    filme[11].datas.dia = 22;
    filme[11].datas.ano = 2000;
    filme[11].restricao = 16;
    strcpy(filme[11].datas.mes, "Setembro");
    strcpy(filme[12].nome_filme, "O Grito");
    strcpy(filme[12].genero, "Terror");
    strcpy(filme[12].diretor, "Takashi Shimizu");
    strcpy(filme[12].atores_principais, "Sarah Michelle Gellar, Jason Behr, Clea DuVall, KaDee Strickland, Bill Pullman, William Mapother, Grace Zabriskie, Rosa Blasi");
    strcpy(filme[12].sinopse, "Em Toquio uma casa comum oculta o pavor que nela ha, pois quando alguem morre em um momento de terror nasce uma maldicao,\n"
                              "que nao perdoa nem esquece e faz as pessoas morrerem vitimadas por uma poderosa ira.\n"
                              "Neste contexto surge a estudante americana Karen Davis (Sarah Michelle Gellar), que, desconhecendo a maldicao, esta no Japao em um intercambio cultural.\n"
                              "Karen eh voluntaria do Centro Social de Apoio, pois isto conta credito para sua formatura na faculdade.\n"
                              "Ela inocentemente concorda em substituir uma assistente social que nao foi trabalhar, sem saber que ela na verdade foi vitima da maldicao.\n"
                              "Karen vai ate a casa amaldicoada para cuidar de Emma Williams (Grace Zabriskie), que tem uma letargia grave associada a leve demencia,\n"
                              "o que a faz ficar dormindo quase todo o dia. Ao chegar ve Emma em um estado catatonico, enquanto o resto da casa parece estar abandonado e desordenado.\n"
                              "Enquanto cuidava de Emma, Karen ouve estranhos sons na parte de cima da casa. Ao investigar ela se defronta com algo tao apavorante que seria incapaz de imaginar,\n"
                              "pois dentro da casa ha uma sucessao de fatos apavorantes que sao o resultado de algo terrivelmente malefico, que surgiu de forma horrenda anos atras.\n"
                              "Como mais pessoas morrem, Karen eh envolvida no ciclo de horror e aprende o segredo da maldicao vingativa, que criou raizes nesta casa.\n"
                              "Agora ela tenta parar isto antes que seja muito tarde, mas por mais que ela aprenda sobre a maldicao e suas origens a forca malefica que Karen\n"
                              "enfrenta eh algo que ela ainda nao dimensionou.");
    filme[12].duracao_min = 96;
    filme[12].datas.dia = 7;
    filme[12].datas.ano = 2005;
    filme[12].restricao = 14;
    strcpy(filme[12].datas.mes, "Janeiro");
    strcpy(filme[13].nome_filme, "O Massacre da Serra Eletrica");
    strcpy(filme[13].genero, "Terror");
    strcpy(filme[13].diretor, "Tobe Hooper");
    strcpy(filme[13].atores_principais, "Marilyn Burns, Allen Danziger, Paul A. Partain, William Vail, Teri McMinn, Edwin Neal, Jim Siedow, Gunnar Hansen");
    strcpy(filme[13].sinopse, "Em 1973, a policia texana deu como encerrado o caso de um terrivel massacre de 33 pessoas provocado por um homem que usava uma mascara feita de pele humana.\n"
                              "Nos anos que se seguiram os policiais foram acusados de fazer uma pessima investigacao e de terem matado o cara errado.\n"
                              "Se que dessa vez, o unico sobrevivente do massacre vai contar em detalhes o que realmente aconteceu na deserta estrada do Texas,\n"
                              "quando ele e mais 4 amigos estavam indo visitar o seu avo");
    filme[13].duracao_min = 90;
    filme[13].datas.dia = 28;
    filme[13].datas.ano = 1987;
    filme[13].restricao = 18;
    strcpy(filme[13].datas.mes, "Agosto");
    strcpy(filme[14].nome_filme, "Kingsman Servico Secreto");
    strcpy(filme[14].genero, "Acao");
    strcpy(filme[14].diretor, "Matthew Vaughn");
    strcpy(filme[14].atores_principais, "Colin Firth, Samuel L. Jackson, Taron Egerton, Mark Strong, Michael Caine, Sofia Boutella, Sophie Cookson, Mark Hamill");
    strcpy(filme[14].sinopse, "Eggsy (Taron Egerton) eh um jovem com problemas de disciplina que parece perto de se tornar um criminoso.\n"
                              "Determinado dia, ele entra em contato com Harry (Colin Firth), que lhe apresenta a agencia de espionagem Kingsman.\n"
                              "O jovem se une a um time de recrutas em busca de uma vaga na agencia. Ao mesmo tempo, Harry tenta impedir a ascensao do vilao Valentine (Samuel L. Jackson).\n"
                              "Adaptacao da serie de quadrinhos criada por Mark Millar e Dave Gibbons.");
    filme[14].duracao_min = 130;
    filme[14].datas.dia = 5;
    filme[14].datas.ano = 2015;
    filme[14].restricao = 16;
    strcpy(filme[14].datas.mes, "Marco");
    strcpy(filme[15].nome_filme, "John Wick: De Volta ao Jogo");
    strcpy(filme[15].genero, "Acao");
    strcpy(filme[15].diretor, "Chad Stahelski");
    strcpy(filme[15].atores_principais, "Keanu Reeves, Michael Nyqvist, Alfie Allen, Adrianne Palicki, Bridget Moynahan, Ian McShane, John Leguizamo, Willem Dafoe");
    strcpy(filme[15].sinopse, "John Wick (Keanu Reeves) ja foi um dos assassinos mais temidos da cidade de Nova York, trabalhando em parceria com a mafia russa.\n"
                              "Um dia, ele decide se aposentar, e neste periodo tem que lidar com a triste morte de sua esposa.\n"
                              "Vitima de uma doenca grave, ela ja previa a sua propria morte, e deu de presente ao marido um cachorro para cuidar em seu periodo de luto.\n"
                              "No entanto, poucos dias apos o funeral, o cachorro eh morto por ladroes que roubam o seu carro.\n"
                              "John Wick parte em busca de vinganca contra estes homens que ele ja conhecia muito bem, e que roubaram o ultimo simbolo da mulher que ele amava.");
    filme[15].duracao_min = 101;
    filme[15].datas.dia = 27;
    filme[15].datas.ano = 2014;
    filme[15].restricao = 16;
    strcpy(filme[15].datas.mes, "Novembro");
    strcpy(filme[16].nome_filme, "Interestelar");
    strcpy(filme[16].genero, "Sci-Fi");
    strcpy(filme[16].diretor, "Christopher Nolan");
    strcpy(filme[16].atores_principais, "Matthew McConaughey, Anne Hathaway, Michael Caine, John Lithgow, Jessica Chastain, Mackenzie Foy, Wes Bentley");
    strcpy(filme[16].sinopse, "Apos ver a Terra consumindo boa parte de suas reservas naturais, um grupo de astronautas recebe a missao de verificar possiveis planetas\n"
                              "para receberem a populacao mundial, possibilitando a continuacao da especie. Cooper (Matthew McConaughey) eh chamado para liderar o grupo e\n"
                              "aceita a missao sabendo que pode nunca mais ver os filhos. Ao lado de Brand (Anne Hathaway), Jenkins (Marlon Sanders) e Doyle (Wes Bentley),\n"
                              "ele seguira em busca de uma nova casa. Com o passar dos anos, sua filha Murph (Mackenzie Foy e Jessica Chastain) investira numa prapria jornada\n"
                              "para tambem tentar salvar a populacao do planeta.");
    filme[16].duracao_min = 169;
    filme[16].datas.dia = 6;
    filme[16].datas.ano = 2014;
    filme[16].restricao = 10;
    strcpy(filme[16].datas.mes, "Novembro");


    return Catalogo;
}

void muda2(char genero1[15])
{
    int i;
    for(i=0;genero1[i]!='\0';i++){
        if(genero1[i]>='A' && genero1[i]<='Z'){
            genero1[i] += 32;
        }
    }
}

void Filmes_generos(struct Filmes filme[1000],struct Data_Lancamento datas, char genero[15], int idades)
{
    int i;
    char genero1[15];
    for(i=0;i<1000;i++){
        strcpy(genero1,filme[i].genero);
        muda2(genero1);
        if((filme[i].duracao_min)!=NULL && idades>=18 && (strcmp(genero1,genero))==0){
        printf("\n\n\nFilme: %s\n", filme[i].nome_filme);
        printf("Genero: %s\n", filme[i].genero);
        printf("Diretor: %s\n", filme[i].diretor);
        printf("Principais Atores/Atrizes: %s\n", filme[i].atores_principais);
        if((filme[i].restricao)==0){
            printf("Classificacao Indicativa: Livre\n");
        }else{
            printf("Classificacao Indicativa: %d\n", filme[i].restricao);
        }
        printf("Sinopse:\n  %s\n\n", filme[i].sinopse);
        printf("Duracao: %d minutos\n", filme[i].duracao_min);
        printf("Data de Lancamento: %d de %s de %d\n\n\n", filme[i].datas.dia, filme[i].datas.mes, filme[i].datas.ano);
        } else if((filme[i].duracao_min)!=NULL && idades<18 && (strcmp(filme[i].genero,genero))==0){
            if((filme[i].restricao)<=idades){
                printf("\n\n\nFilme: %s\n", filme[i].nome_filme);
                printf("Genero: %s\n", filme[i].genero);
                printf("Diretor: %s\n", filme[i].diretor);
                printf("Principais Atores/Atrizes: %s\n", filme[i].atores_principais);
                if((filme[i].restricao)==0){
                printf("Classificacao Indicativa: Livre\n");
                }else{
                    printf("Classificacao Indicativa: %d\n", filme[i].restricao);
                }
                printf("Sinopse:\n  %s\n\n", filme[i].sinopse);
                printf("Duracao: %d minutos\n", filme[i].duracao_min);
                printf("Data de Lancamento: %d de %s de %d\n\n\n", filme[i].datas.dia, filme[i].datas.mes, filme[i].datas.ano);
            }
        }
    }
    return Filmes_generos;
}

void Filmes_todos(struct Filmes filme[1000],struct Data_Lancamento datas, int idades)
{
    int i;
    for(i=0;i<1000;i++){
        if((filme[i].duracao_min)!=NULL && idades>=18){
        printf("\n\n\nFilme: %s\n", filme[i].nome_filme);
        printf("Genero: %s\n", filme[i].genero);
        printf("Diretor: %s\n", filme[i].diretor);
        printf("Principais Atores/Atrizes: %s\n", filme[i].atores_principais);
        if((filme[i].restricao)==0){
            printf("Classificacao Indicativa: Livre\n");
        }else{
            printf("Classificacao Indicativa: %d\n", filme[i].restricao);
        }
        printf("Sinopse:\n  %s\n\n", filme[i].sinopse);
        printf("Duracao: %d minutos\n", filme[i].duracao_min);
        printf("Data de Lancamento: %d de %s de %d\n\n\n", filme[i].datas.dia, filme[i].datas.mes, filme[i].datas.ano);
        } else if((filme[i].duracao_min)!=NULL && idades<18){
            if((filme[i].restricao)<=idades){
            printf("\n\n\nFilme: %s\n", filme[i].nome_filme);
            printf("Genero: %s\n", filme[i].genero);
            printf("Diretor: %s\n", filme[i].diretor);
            printf("Principais Atores/Atrizes: %s\n", filme[i].atores_principais);
            if((filme[i].restricao)==0){
                printf("Classificacao Indicativa: Livre\n");
            }else{
                printf("Classificacao Indicativa: %d\n", filme[i].restricao);
            }
            printf("Sinopse:\n  %s\n\n", filme[i].sinopse);
            printf("Duracao: %d minutos\n", filme[i].duracao_min);
            printf("Data de Lancamento: %d de %s de %d\n\n\n", filme[i].datas.dia, filme[i].datas.mes, filme[i].datas.ano);
            }
        }
    }
    return Filmes_todos;
}

void muda(char nome[100])
{
    int i;
    for(i=0;nome[i]!='\0';i++){
        if(nome[i]>='A' && nome[i]<='Z'){
            nome[i] += 32;
        } else if(nome[i]=='&'){
            nome[i] = 'e';
        }
    }
}

void muda1(char nome1[100])
{
    int i;
    for(i=0;nome1[i]!='\0';i++){
        if(nome1[i]>='A' && nome1[i]<='Z'){
            nome1[i] += 32;
        } else if(nome1[i]=='&'){
            nome1[i] = 'e';
        } else if(nome1[i]==':'){
            nome1[i] = ' ';
        }
    }
}

void Filmes_nome(struct Filmes filme[1000],struct Data_Lancamento datas, int idades)
{
    int i,j,c;
    char nome_film[100], aux[100], nome[100], nome1[100], *pt = NULL;
    printf("Digite o nome do filme que procura:\n");
    gets(nome_film);
    setbuf(stdin,NULL);
    strcpy(nome,nome_film);
    muda(nome);
    for(i=0;i<1000;i++){
        strcpy(nome1,filme[i].nome_filme);
        muda1(nome1);
        pt = strstr(nome1,nome);
        if((filme[i].duracao_min)!=NULL && idades>=18 && pt!=NULL){
            c = i;
            break;
        } else if ((filme[i].duracao_min)!=NULL && idades<18 && pt!=NULL){
            c = i;
            break;
        }
    }
    if(c==1000){
        c-=5;
    }
    for(i=c;i<1000;i++){
        if((filme[i].duracao_min)!=NULL && idades>=18 && pt!=NULL){
            for(j=0;nome1[j]!='\0';j++){
                if(nome1[j]==' '){
                    nome1[j]='.';
                }
            }
            sprintf(aux,"%s.jpg",nome1);
            system(aux);
            printf("\n\n\nFilme: %s\n", filme[i].nome_filme);
            printf("Genero: %s\n", filme[i].genero);
            printf("Diretor: %s\n", filme[i].diretor);
            printf("Principais Atores/Atrizes: %s\n", filme[i].atores_principais);
            if((filme[i].restricao)==0){
                printf("Classificacao Indicativa: Livre\n");
            }else{
                printf("Classificacao Indicativa: %d\n", filme[i].restricao);
            }
            printf("Sinopse:\n  %s\n\n", filme[i].sinopse);
            printf("Duracao: %d minutos\n", filme[i].duracao_min);
            printf("Data de Lancamento: %d de %s de %d\n\n\n", filme[i].datas.dia, filme[i].datas.mes, filme[i].datas.ano);
            break;
            } else if((filme[i].duracao_min)!=NULL && idades<18 && pt!=NULL && (filme[i].restricao)>idades){
                printf("\nVoce nao tem idade para ver esse filme, complete %d anos primeiro e depois volte =)\n\n\n", filme[i].restricao);
                break;
            } else if((filme[i].duracao_min)!=NULL && idades<18 && pt!=NULL && (filme[i].restricao)<=idades){
                for(j=0;nome_film[j]!='\0';j++){
                    if(nome_film[j]==' '){
                        nome_film[j]='.';
                    }
                }
                sprintf(aux,"%s.jpg",nome_film);
                system(aux);
                printf("\n\n\nFilme: %s\n", filme[i].nome_filme);
                printf("Genero: %s\n", filme[i].genero);
                printf("Diretor: %s\n", filme[i].diretor);
                printf("Principais Atores/Atrizes: %s\n", filme[i].atores_principais);
                if((filme[i].restricao)==0){
                    printf("Classificacao Indicativa: Livre\n");
                }else{
                    printf("Classificacao Indicativa: %d\n", filme[i].restricao);
                }
                printf("Sinopse:\n  %s\n\n", filme[i].sinopse);
                printf("Duracao: %d minutos\n", filme[i].duracao_min);
                printf("Data de Lancamento: %d de %s de %d\n\n\n", filme[i].datas.dia, filme[i].datas.mes, filme[i].datas.ano);
                break;
        } else if((filme[i].duracao_min)!=NULL && idades>=18 && pt==NULL){
            printf("\n\nFilme nao encontrado!\n\n");
            printf("OBS: Voce pode ter digitado o nome erroneamente!\n"
                   "Quando maior parecido for o que voce escreveu com o nome do filme, maior chance de encontrar corretamente!!\n\n\n");
            break;
        }
    }
    return Filmes_nome;
}

void Filmes_ordem(struct Filmes filme[1000],struct Data_Lancamento datas)
{
    char aux1[1600];
    int aux = 0, i, j;
    for(i=0;i<1000;i++){
        for(j=i+1;j<1000;j++){
            if(((filme[i].datas.ano)!=NULL) || ((filme[j].datas.ano)!=NULL) ){
                if(filme[i].datas.ano>=filme[j].datas.ano){
                    strcpy(aux1,filme[i].nome_filme);
                    strcpy(filme[i].nome_filme,filme[j].nome_filme);
                    strcpy(filme[j].nome_filme,aux1);
                    strcpy(aux1,filme[i].genero);
                    strcpy(filme[i].genero,filme[j].genero);
                    strcpy(filme[j].genero,aux1);
                    strcpy(aux1,filme[i].diretor);
                    strcpy(filme[i].diretor,filme[j].diretor);
                    strcpy(filme[j].diretor,aux1);
                    strcpy(aux1,filme[i].atores_principais);
                    strcpy(filme[i].atores_principais,filme[j].atores_principais);
                    strcpy(filme[j].atores_principais,aux1);
                    strcpy(aux1,filme[i].sinopse);
                    strcpy(filme[i].sinopse,filme[j].sinopse);
                    strcpy(filme[j].sinopse,aux1);
                    strcpy(aux1,filme[i].datas.mes);
                    strcpy(filme[i].datas.mes,filme[j].datas.mes);
                    strcpy(filme[j].datas.mes,aux1);
                    aux = filme[i].datas.ano;
                    filme[i].datas.ano = filme[j].datas.ano;
                    filme[j].datas.ano = aux;
                    aux = filme[i].datas.dia;
                    filme[i].datas.dia = filme[j].datas.dia;
                    filme[j].datas.dia = aux;
                    aux = filme[i].restricao;
                    filme[i].restricao = filme[j].restricao;
                    filme[j].restricao = aux;
                    aux = filme[i].duracao_min;
                    filme[i].duracao_min = filme[j].duracao_min;
                    filme[j].duracao_min = aux;
                    aux = filme[i].codigo_filme;
                    filme[i].codigo_filme = filme[j].codigo_filme;
                    filme[j].codigo_filme = aux;
                }
            }
        }
    }
    return Filmes_ordem;
}

void cadastrar_filme(struct Filmes filme[1000],struct Data_Lancamento datas)
{
    int i;
    double mds;
    char c='1';
    while(c=='1'){
        for(i=0;i<1000;i++){
            if(filme[i].duracao_min==NULL){
                printf("Digite o nome do filme:\n");
                gets(filme[i].nome_filme);
                setbuf(stdin,NULL);
                printf("\nDigite o genero do filme:\n");
                gets(filme[i].genero);
                setbuf(stdin,NULL);
                printf("\nDigite o(s)/a(s) diretor(es)/diretora(as) do filme:\n");
                gets(filme[i].diretor);
                setbuf(stdin,NULL);
                printf("\nDigite apenas os(as) principais atores/atrizes:\n");
                gets(filme[i].atores_principais);
                setbuf(stdin,NULL);
                printf("\nDigite a classificacao indicativa:\n");
                printf("OBS: Se for livre, digite 0\n");
                scanf("%lf", &mds);
                filme[i].restricao = mds;
                setbuf(stdin,NULL);
                while((filme[i].restricao)<0){
                    printf("\nDigite a classificacao indicativa:\n");
                    printf("OBS: Se for livre, digite 0\n");
                    scanf("%lf", &mds);
                    filme[i].restricao = mds;
                    setbuf(stdin,NULL);
                }
                printf("\nDigite a sinopse do filme:\n");
                gets(filme[i].sinopse);
                setbuf(stdin,NULL);
                printf("\nDigite a duracao do filme em minutos:\n");
                scanf("%lf", &mds);
                filme[i].duracao_min = mds;
                setbuf(stdin,NULL);
                while((filme[i].duracao_min)<=0){
                    printf("\nDigite a duracao do filme em minutos:\n");
                    scanf("%lf", &mds);
                    filme[i].duracao_min = mds;
                    setbuf(stdin,NULL);
                }
                printf("\nDigite o dia de lancamento do filme:\n");
                scanf("%lf", &mds);
                filme[i].datas.dia = mds;
                setbuf(stdin,NULL);
                while((filme[i].datas.dia)<=0 || (filme[i].datas.dia)>31){
                    printf("\nDigite o dia de lancamento do filme:\n");
                    scanf("%lf", &mds);
                    filme[i].datas.dia = mds;
                    setbuf(stdin,NULL);
                }
                printf("\nEscreva o mes de lancamento:\n");
                gets(filme[i].datas.mes);
                setbuf(stdin,NULL);
                printf("\nDigite o ano de lancamento do filme:\n");
                scanf("%lf", &mds);
                filme[i].datas.ano = mds;
                setbuf(stdin,NULL);
                while((filme[i].datas.ano)<=1800){
                    printf("\nDigite o ano de lancamento do filme:\n");
                    scanf("%lf", &mds);
                    filme[i].datas.ano = mds;
                    setbuf(stdin,NULL);
                }
            } else {
                continue;
            }
            printf("Filme cadastrado com sucesso! O codigo para acessa-lo eh: %d\n\n", filme[i].codigo_filme);
            break;
        }
        if(i!=1000){
            printf("Deseja adicionar algum outro filme?\n(1)Sim\n(2)Nao\n");
            scanf("%s", &c);
            setbuf(stdin,NULL);
            while(c!='2' && c!='1'){
                printf("Deseja adicionar algum outro filme?\n(1)Sim\n(2)Nao\n");
                scanf("%s", &c);
                setbuf(stdin,NULL);
            }
        }
    }
    return cadastrar_filme;
}

void alterar_filme(struct Filmes filme[1000],struct Data_Lancamento datas)
{
    int i, c;
    double mds;
    char b, a, d='1';
    while(d=='1'){
        printf("Digite o codigo do filme que deseja alterar:\n");
        scanf("%lf", &mds);
        c = mds;
        setbuf(stdin,NULL);
        while(c<=0){
            printf("Codigo errado!\n");
            printf("Digite o codigo do filme que deseja alterar:\n");
            scanf("%lf", &mds);
            c = mds;
            setbuf(stdin,NULL);
        }
        for(i=0;i<1000;i++){
            if(c==(filme[i].codigo_filme)){
                if((filme[i].duracao_min) == NULL){
                    printf("Filme nao existente!\n\n\n");
                    break;
                } else {
                    a='1';
                    while(a=='1'){
                        filmess(filme,datas,i);
                        printf("O que voce deseja alterar?\n");
                        printf("1) Nome do filme\n2) Genero do filme\n3) Diretor(a)\n4) Principais atores/atrizes\n5) Classificacao Indicativa\n6) Sinopse\n7) Duracao\n8) Data de lancamento\n");
                        scanf("%s", &b);
                        setbuf(stdin,NULL);
                        switch(b){
                            case '1':
                                printf("Digite o nome do filme:\n");
                                gets(filme[i].nome_filme);
                                setbuf(stdin,NULL);
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                            case '2':
                                printf("\nDigite o genero do filme:\n");
                                gets(filme[i].genero);
                                setbuf(stdin,NULL);
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                            case '3':
                                printf("\nDigite o(s)/a(s) diretor(es)/diretora(as) do filme:\n");
                                gets(filme[i].diretor);
                                setbuf(stdin,NULL);
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                            case '4':
                                printf("\nDigite apenas os(as) principais atores/atrizes:\n");
                                gets(filme[i].atores_principais);
                                setbuf(stdin,NULL);
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                            case '5':
                                printf("\nDigite a classificacao indicativa:\n");
                                printf("OBS: Se for livre, digite 0\n");
                                scanf("%lf", &mds);
                                filme[i].restricao = mds;
                                setbuf(stdin,NULL);
                                while((filme[i].restricao)<0){
                                    printf("\nDigite a classificacao indicativa:\n");
                                    printf("OBS: Se for livre, digite 0\n");
                                    scanf("%lf", &mds);
                                    filme[i].restricao = mds;
                                    setbuf(stdin,NULL);
                                }
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                            case '6':
                                printf("\nDigite a sinopse do filme:\n");
                                gets(filme[i].sinopse);
                                setbuf(stdin,NULL);
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                            case '7':
                                printf("\nDigite a duracao do filme em minutos:\n");
                                scanf("%lf", &mds);
                                filme[i].duracao_min = mds;
                                setbuf(stdin,NULL);
                                while((filme[i].duracao_min)<=0){
                                    printf("\nDigite a duracao do filme em minutos:\n");
                                    scanf("%lf", &mds);
                                    filme[i].duracao_min = mds;
                                    setbuf(stdin,NULL);
                                }
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                            case '8':
                                printf("\nDigite o dia de lancamento do filme:\n");
                                scanf("%lf", &mds);
                                filme[i].datas.dia = mds;
                                setbuf(stdin,NULL);
                                while((filme[i].datas.dia)<=0 || (filme[i].datas.dia)>31){
                                    printf("\nDigite o dia de lancamento do filme:\n");
                                    scanf("%lf", &mds);
                                    filme[i].datas.dia = mds;
                                    setbuf(stdin,NULL);
                                }
                                printf("\nEscreva o mes de lancamento:\n");
                                gets(filme[i].datas.mes);
                                setbuf(stdin,NULL);
                                printf("\nDigite o ano de lancamento do filme:\n");
                                scanf("%lf", &mds);
                                filme[i].datas.ano = mds;
                                setbuf(stdin,NULL);
                                while((filme[i].datas.ano)<=1800){
                                    printf("\nDigite o ano de lancamento do filme:\n");
                                    scanf("%lf", &mds);
                                    filme[i].datas.ano = mds;
                                    setbuf(stdin,NULL);
                                }
                                printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                scanf("%s", &a);
                                setbuf(stdin,NULL);
                                while(a!='2' && a!='1'){
                                    printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
                                    scanf("%s", &a);
                                    setbuf(stdin,NULL);
                                }
                            break;
                        }
                    }
                }
            }
        }
        printf("Deseja alterar os dados de algum outro filme?\n(1)Sim\n(2)Nao\n");
        scanf("%s", &d);
        setbuf(stdin,NULL);
        while(d!='2' && d!='1'){
            printf("Deseja alterar mais alguma coisa?\n(1)Sim\n(2)Nao\n");
            scanf("%s", &d);
            setbuf(stdin,NULL);
        }
    }
    return alterar_filme;
}

void filmess(struct Filmes filme[1000],struct Data_Lancamento datas, int i)
{
    printf("\n\n\nCodigo do filme: %d\n", filme[i].codigo_filme);
    printf("Filme: %s\n", filme[i].nome_filme);
    printf("Genero: %s\n", filme[i].genero);
    printf("Diretor: %s\n", filme[i].diretor);
    printf("Principais Atores/Atrizes: %s\n", filme[i].atores_principais);
        if((filme[i].restricao)==0){
            printf("Classificacao Indicativa: Livre\n");
        }else{
            printf("Classificacao Indicativa: %d\n", filme[i].restricao);
        }
        printf("Sinopse:\n  %s\n\n", filme[i].sinopse);
        printf("Duracao: %d minutos\n", filme[i].duracao_min);
        printf("Data de Lancamento: %d de %s de %d\n\n\n", filme[i].datas.dia, filme[i].datas.mes, filme[i].datas.ano);
        return filmess;
}

void remover_filme(struct Filmes filme[1000],struct Data_Lancamento datas)
{
    int i, c;
    double mds;
    char a='1', t;
    while(a=='1'){
        printf("Digite o codigo do filme que deseja remover:\n");
        scanf("%lf", &mds);
        c = mds;
        setbuf(stdin,NULL);
        while(c<=0){
            printf("Codigo errado!\n");
            printf("Digite o codigo do filme que deseja remover:\n");
            scanf("%lf", &mds);
            c = mds;
            setbuf(stdin,NULL);
        }
        for(i=0;i<1000;i++){
            if(c==(filme[i].codigo_filme)){
                if((filme[i].duracao_min) == NULL){
                    printf("Filme nao existente!\n\n\n");
                    break;
                } else {
                    filmess(filme,datas,i);
                    printf("Tem certeza que deseja remover esse filme?\n(1)Sim\n(2)Nao\n");
                    scanf("%s",&t);
                    if(t=='2'){
                        break;
                    } else if(t=='1'){
                        strcpy(filme[i].nome_filme," ");
                        strcpy(filme[i].genero," ");
                        strcpy(filme[i].diretor," ");
                        strcpy(filme[i].atores_principais," ");
                        strcpy(filme[i].sinopse," ");
                        filme[i].duracao_min = NULL;
                        filme[i].datas.dia = NULL;
                        filme[i].datas.ano = NULL;
                        filme[i].restricao = NULL;
                        strcpy(filme[i].datas.mes," ");
                        break;
                    }
                }
            }
        }
        printf("Deseja remover outro filme?\n(1)Sim\n(2)Nao\n");
        scanf("%s", &a);
        setbuf(stdin,NULL);
        while(a!='1' && a!='2'){
            printf("Deseja remover outro filme?\n(1)Sim\n(2)Nao\n");
            scanf("%s", &a);
            setbuf(stdin,NULL);
        }
    }
    printf("Filme(s) removido com sucesso!\n");
    return remover_filme;
}
