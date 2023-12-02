#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_ITEM 50


/**
 * Uma variavel usada para armazenar a quantidade de passageiros cadastrado,
 * usado para criar o ID do passageiro e para verificar se o passageiro inserido ainda não foi cadastrado
 */
int contPassageiro = 0;
/**
 * Uma matriz para guardar a estação como posição (de 0 a 4) e a quantidade de passageiros, sendo
 * a primeira posição as entradas e a segunda a saida
 */
int totalPassageiros[5][2]; //Uma matriz para guardar a estação como posição (de 1 a 5) e a quantidade de passageiros, sendo a primeira posição as entradas e a segunda a saida

/**
 * Elemento Struct Passageiro que ira ser utilizado atraves do codigo, contendo as informaçoes do passageiro,
 * as informaçoes sobre o horario de entrada e saída do passageiro e as estaçoes que o passageiro entrou e saiu
 */
typedef struct Passageiro{
    int idCartao;
    char nomePassageiro[100];
    time_t horarioEntrada;
    time_t horarioSaida;
    int estacaoEntrada;
    int estacaoSaida;
} passageiro;

typedef passageiro *p_passageiro;
p_passageiro pa[MAX_ITEM];

void inicializa();

void cadastroPassageiro();

void registrarEntrada(int idCartao, time_t horarioEntrada, int estacaoEntrada);

void registrarSaida(int idCartao, time_t horarioSaida, int estacaoSaida);

void gerarRelatorio(time_t inicioIntervalo, time_t fimIntervalo, const char *nomeArquivo);

void visualizarFluxoEstacao(int estacao);

/**
 * Esta função é a Main do codigo onde nela o usuario ira utilizar um menu disponibilizando o acesso as
 * outras funçoes encontradas no codigo
 */
int main() {
    inicializa();

    int opc = -1;

    /*
     * Variaveis de tempo do time.h
     */

    time_t inicioIntervalo;
    time(&inicioIntervalo);
    time_t horarioEntrada;
    time_t horarioSaida;
    time_t fimIntervalo;

    struct tm* infoTempo; //Estrutura para informar o tempo em que o o time_t foi gerado.

    const char *nomeArquivo = "relatorio.txt"; //O nome do arquivo gerado ao rodar Função gerarRelatorio

    int idCartao = 0;
    int estacao = 0;


    //função para limpar totalPassageiros
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            totalPassageiros[i][j] = 0;
        }
    }

    /*
     * Menu do programa, nele é possivel Registrar a entrada do passageiro, Registrar a saida
     * Gerar relatorio e visualizar fluxo das Estações.
     */
    while (opc != 0){
        printf("*------ MENU ------*\n");
        printf("1. Registrar entrada\n");
        printf("2. Registrar saida\n");
        printf("3. Gerar relatorio\n");
        printf("4. Visualizar fluxo de estacao\n");
        printf("0. Sair\n");

        if (scanf("%d", &opc) != 1){
            printf("ERRO: Invalido");

        }

        int teste;
        switch (opc) {
            case 1:
                //registrar entrada
                printf("\n-------------------\n");
                printf("Registrando entrada...\n");
                printf("Escolha o ID do passageiro que deseja: \n");
                scanf("%d", &idCartao);

                time(&horarioEntrada);

                infoTempo = localtime(&horarioEntrada);
                printf("Horario atual de entrada: %02d:%02d:%02d\n",
                       infoTempo->tm_hour, infoTempo->tm_min, infoTempo->tm_sec);


                printf("\nInsira o numero da estacao de entrada: ");
                scanf("%d", &estacao);

                registrarEntrada(idCartao, horarioEntrada,estacao);

                break;
            case 2:
                //registrar saida

                printf("\n-------------------\n");
                printf("Registrando saida...\n");
                printf("Escolha o ID do passageiro que deseja: \n");
                scanf("%d", &idCartao);

                time(&horarioSaida);

                infoTempo = localtime(&horarioSaida);
                printf("Horario atual de saida: %02d:%02d:%02d\n",
                       infoTempo->tm_hour, infoTempo->tm_min, infoTempo->tm_sec);

                printf("\nInsira o numero da estacao de saida: ");
                scanf("%d", &estacao);

                registrarSaida(idCartao,horarioSaida,estacao);
                break;
            case 3:
                //gerar relatorio
                time(&fimIntervalo);

                gerarRelatorio(inicioIntervalo, fimIntervalo, nomeArquivo);

                time(&inicioIntervalo);
                break;
            case 4:
                //fluxo de estação
                printf("Digite o numero da estacao para consulta: \n");
                printf("(Estacao 0: Tucuquara - Jabaruvi | Estacao 1: Madalente - Prudelena | "
                       "Estacao 2: Barra Rasa - Itatenha | Estacao 3: Muruta - Sombra | "
                       "Estacao 4: Capao quadrado - Klalixo)\n");
                scanf("%d", &estacao);

                if(estacao < 0 || estacao > 4){
                    printf("Estacao invalida! Insira da lista apresentada\n");
                    break;
                }

                visualizarFluxoEstacao(estacao);

                break;
            case 0:
                printf("\nSaindo...");
                break;

            default:
                printf("Invalido\n");
                break;
        }
    }

    return 0;
}

/*
 * Função fundamental para o funcionamento do typedef Struct
 * ele inicializa limpando completamente o ponteiro para que não haja interferencia ao
 * passar dados para o struct.
 */
void inicializa(){
    int i;
    for (i = 0; i < MAX_ITEM; ++i) {
        pa[i] = NULL;
    }
}

/**
 * Esta função tem como objetivo realizar o cadastro de novos passageiros, utilizando a estrutura Passageiro o usuario ira
 * inserir o nome do novo passageiro enquanto o codigo ira atribuir a esse passageiro um ID
 *
 * NOTA PARA O PROFESSOR MAROMO!!!!!!!!!
 *  - Não atingimos o total funcionamento da alocação de memoria.
 *  - Ao gerar uma nova entrada para o ponteiro do Struct Passageiros os dados anteriormente guardados
 *  são perdidos. Ocasionando na exclusão do ID e nome.
 */
void cadastroPassageiro(){
    if (pa [contPassageiro]==NULL){
        pa[contPassageiro] = (p_passageiro)malloc(sizeof(passageiro));
        pa[contPassageiro]->idCartao = contPassageiro;
        fflush(stdin);
        printf("Digite o nome do passageiro: \n");
        gets(pa[contPassageiro]->nomePassageiro);
        contPassageiro = contPassageiro + 1;
    }

}

/**
 * Esta função tem como objetivo registrar o horario de entrada do passageiro em estação e em qual estação ele entrou,
 * em caso do usuario inserira um passageiro não cadastrado o codigo ira redirecionar o usuario para função cadastrarPassgeiro
 * @param idCartao Este paramentro recebe o Id do passagerio inserido pelo usuario, sendo usado para encontrar os dados de
 * um passageiro especifico na estrutura passageiros
 * @param horarioEntrada Este parametro recebe o horario em que foi iniciado a função registrarEntrada automaticamente
 * atraves da biblioteca time.h
 * @param estacaoEntrada Este paramentro recebe um numero que serve para indentificar a estação de entrada do passageiro
 */
void registrarEntrada(int idCartao, time_t horarioEntrada, int estacaoEntrada){


    if(pa[idCartao] == NULL) {
        cadastroPassageiro();
    }

    free(pa[contPassageiro]);
    pa[idCartao] = (p_passageiro)malloc(sizeof(passageiro));
    pa[idCartao]->horarioEntrada = horarioEntrada;
    pa[idCartao]->estacaoEntrada = estacaoEntrada;



    totalPassageiros[estacaoEntrada][0] = totalPassageiros[estacaoEntrada][0] + 1;


    printf("\nEntrada registrada!\n");

    return;
}

/**
 * Esta função tem como objetivo registrar o horario de saída do passageiro em estação e em qual estação ele saiu,
 * em caso do usuario inserira um passageiro não cadastrado o codigo ira redirecionar o usuario para função cadastrarPassgeiro,
 * esta função também verifica se o horario de saída do passageiro foi regitrado antes do horario de entrada
 * @param idCartao Este paramentro recebe o Id do passagerio inserido pelo usuario, sendo usado para encontrar os dados de
 * um passageiro especifico na estrutura passageiros
 * @param horarioSaida Este parametro recebe o horario em que foi iniciado a função registrarSaida automaticamente
 * atraves da biblioteca time.h
 * @param estacaoSaida Este paramentro recebe um numero que serve para indentificar a estação de saída do passageiro
 */
void registrarSaida(int idCartao, time_t horarioSaida, int estacaoSaida){
    if(pa[idCartao] == NULL) {
        cadastroPassageiro();
    }

    time_t t1 = pa[idCartao]->horarioEntrada;

    /*
     * Esse if não está funcionando corretamente pelo mesmo problema de alocação de memoria.
     * o funcionamento correto é: receber o tempo time_t correspondente ao horarioEntrada do
     * struct e usa como comparação a entrada de estacaoSaida onde, senão e corresponder
     * gera uma mensagem de erro e retorna ao main.
     */
    if(t1 > estacaoSaida){
        free(pa[contPassageiro]);
        pa[idCartao] = (p_passageiro)malloc(sizeof(passageiro));
        pa[idCartao]->horarioSaida = horarioSaida;
        pa[idCartao]->estacaoSaida = estacaoSaida;
    }else{
        printf("Operacao invalida, saida do passageiro deve ser registrada depois da entrada. \n");
        return;
    }


    totalPassageiros[estacaoSaida][1] = totalPassageiros[estacaoSaida][1] + 1;


    printf("\nSaida registrada!\n");

    return;

}

/**
 * Esta função cria um arquivo contendo um relatorio geral de todos os passageiros que entraram e saíram das estaçoes
 * dentro de um intervalo de tempo especifico inserido pelo usuario
 * @param inicioIntervalo Este parametro é recebido assim que o sistema é iniciado, marcando o primeiro intervalo de
 * consulta para o relatorio. Após a função gerarRelatorio rodada, gera um novo inicio de intervalo.
 * @param fimIntervalo Este parametro é recebido no switch de gerar relatorio e entregue como parametro para a função.
 * @param nomeArquivo Este parametro é constante e se encontra no corpo do main.
 */
void gerarRelatorio(time_t inicioIntervalo, time_t fimIntervalo, const char *nomeArquivo){
    // Abrir o arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo, "w");



    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escrever cabeçalho no arquivo
    fprintf(arquivo, "Relatório de Fluxo geral das estações\n");
    fprintf(arquivo, "--------------------------------------\n");

    fprintf(arquivo, "Passageiros");
    // Escrever informações de cada funcionário no arquivo

    struct tm* infHEntrada;
    struct tm* infHSaida;

     for (int i = 0; i < contPassageiro; i++) {
         /*
          * Condição, apenas passageiros com entradas e saidas dentro do intervalo serão apresentados no
          * relatorio
          */
        if (pa[i]->horarioEntrada < inicioIntervalo && pa[i]->horarioSaida > fimIntervalo){
            if(pa[i] != NULL){
                fprintf(arquivo, "------------------------\n");
                fprintf(arquivo, "ID do Cartão: %d\n", pa[i]->idCartao);
                fprintf(arquivo, "Nome: %s\n", pa[i]->nomePassageiro);
                fprintf(arquivo, "Horario entrada: %lld\n",pa[i]->horarioEntrada);
                fprintf(arquivo, "Horario saída: %lld\n",pa[i]->horarioSaida);
                fprintf(arquivo, "Estação de entrada: %.d\n", pa[i]->estacaoEntrada);
                fprintf(arquivo, "Estação de Saida: %.d\n", pa[i]->estacaoSaida);
                fprintf(arquivo, "------------------------\n");
            }
        }
     }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 2; ++j) {
            fprintf(arquivo,"Estação %d: Entradas ↑/Saida ↓ [%d] \n",i,totalPassageiros[i][j]);
        }
        fprintf(arquivo,"\n");
    }

    // Fechar o arquivo
    fclose(arquivo);

    printf("Relatorio gerado com sucesso e salvo em %s.\n", nomeArquivo);
}

/**
 * Essa função percorre o Struct Passageiros e filtra os passageiros que correspondem a condição de: a estação de entrada
 * ou de saida do Passageiro apontado pelo ponteiro é igual a recebida pelo parametro.
 * Também exibe o total de passageiros que passaram pela estação apresentando a Matriz totalPassageiros correspondente
 * pela condição apresentada acima.
 *
 * @param estacao Este parametro é recebido pelo usuario para visualizar a estação, deve ser correspondente no intervalo
 * de 0 a 4 para entrar na função.
 */
void visualizarFluxoEstacao( int estacao){
    for (int i = 0; i < contPassageiro; ++i) {
        if(pa[i]->estacaoEntrada == estacao || pa[i]->estacaoSaida == estacao){
            printf("\n-----------------------\n");
            printf("Passageiro com ID: %d\n", pa[i]->idCartao);
            printf("Entrada: %lld\n", pa[i]->horarioEntrada);
            printf("Saida: %lld\n", pa[i]->horarioSaida);
            printf("-----------------------\n");
        }
    }
    for (int i = estacao; i <= estacao; ++i) {
        for (int j = 0; j <= 1; ++j) {
            printf("Estacao %d: Entradas/Saida [%d] \n",i,totalPassageiros[i][j]);
        }
    }
}
