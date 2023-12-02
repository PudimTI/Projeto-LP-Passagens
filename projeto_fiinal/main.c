#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ITEM 20
int contPassageiro = 0;
int totalPassageiros[5][2]; //Uma matriz para guardar a estação como posição (de 1 a 5) e a quantidade de passageiros, sendo a primeira posição as entradas e a segunda a saida



/**
 * Elemento Struct
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

//Passageiro passageiros[MAX_ITEM];

void inicializa();

void cadastroPassageiro();

void registrarEntrada(int idCartao, time_t horarioEntrada, int estacaoEntrada);

void registrarSaida(int idCartao, time_t horarioSaida, int estacaoSaida);

void gerarRelatorio(time_t inicioIntervalo, time_t fimIntervalo, const char *nomeArquivo);

void visualizarFluxoEstacao(int estacao);

int main() {
    inicializa();

    /**
     * Menu do projeto de passagem
     * deve conter
     */
    int opc = -1;

    /*
     * Variaveis de tempo do time.h
     */

    time_t inicioIntervalo;
    time(&inicioIntervalo);
    time_t horarioEntrada;
    time_t horarioSaida;
    time_t fimIntervalo;

    struct tm* infoTempo;


    const char *nomeArquivo = "relatorio.txt";


    //Struct

    //Passageiro passageiro[MAX_ITEM];
    int idCartao = 0;
    int estacao = 0;


    //função para limpar totalPassageiros
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            totalPassageiros[i][j] = 0;
        }
    }

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
                //pa[contPassageiro]->idCartao = contPassageiro;
                printf("\n-------------------\n");
                printf("Registrando entrada...\n");
                printf("Escolha o ID do passageiro que deseja: \n");
                scanf("%d", &idCartao);

                time(&horarioEntrada);

                infoTempo = localtime(&horarioEntrada);
                printf("Horário atual do sistema: %02d:%02d:%02d\n",
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

                printf("\nInsira o numero da estacao de saida: ");
                scanf("%d", &estacao);


                break;
            case 3:
                //gerar relatorio
                time(&fimIntervalo);

                //gerarRelatorio(inicioIntervalo, fimIntervalo);

                time(&inicioIntervalo);
                break;
            case 4:
                //fluxo de estação
                scanf("%d", &teste);

                if(pa[teste] != NULL){
                    printf("IDCARTAO: %d\n", pa[teste]->idCartao);
                    printf("Nome: %s\n", pa[teste]->nomePassageiro);
                    printf("Horario Entrada: %d\n", pa[teste]->horarioEntrada);
                    printf("Horario Saida: %d\n", pa[teste]->horarioSaida);
                    printf("Estacao entrada: %d\n", pa[teste]->estacaoEntrada);
                    printf("Estacao saida: %d\n", pa[teste]->estacaoSaida);

                    printf("Total Passageiros: [%d]\n", totalPassageiros[teste][teste]);
                }

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

void inicializa(){
    int i;
    for (i = 0; i < MAX_ITEM; ++i) {
        pa[i] = NULL;
    }
}

void cadastroPassageiro(){
    if (pa [contPassageiro]==NULL){
        pa[contPassageiro] = (p_passageiro)malloc(sizeof(passageiro));
        fflush(stdin);
        printf("Digite o nome do passageiro: \n");
        gets(pa[contPassageiro]->nomePassageiro);
        pa[contPassageiro]->idCartao = contPassageiro;
        contPassageiro++;
    }



}

void registrarEntrada(int idCartao, time_t horarioEntrada, int estacaoEntrada){


    cadastroPassageiro();



    int estacao = 1;

    pa[idCartao] = (p_passageiro)malloc(sizeof(passageiro));
    pa[idCartao]->horarioEntrada = horarioEntrada;
    pa[idCartao]->estacaoEntrada = estacao;



    /*
     * Adicionar +1 no total de passageiros da estação escolhida.
     *  provavelmente usar Structs para as estações disponiveis MAX 5
    */

    totalPassageiros[estacao][0] = totalPassageiros[estacao][0] + 1;


    printf("\nEntrada registrada!\n");

    return;
}

void registrarSaida(int idCartao, time_t horarioSaida, int estacaoSaida){
    //Passageiro* passageiro[MAX_ITEM];
    int estacao;


    if (idCartao < 0 && idCartao > contPassageiro){
        printf("ID não encontrado.\n");
        printf("Cadastrando novo passageiro...\n");
        cadastroPassageiro();
        idCartao = contPassageiro;

        return; //Para fazer: um metodo de perguntar no caso de criar um novo Passageiro ou digitar um novo numero
    }else{
        idCartao = contPassageiro;
    }


    //time_t t1 = mktime(&horarioSaida);
    //time_t t2 = passageiro[idCartao]->horarioEntrada;

   // if (t1 < t2){
    //    printf("Tempo de saida invalido, tempo de saida antes de passageiro entrar\n");
    //    return;
   /// }

    //passageiro[idCartao].horarioSaida = t1;

    printf("\nInsira o numero da estação de saida do metro.");
    scanf("%d", &estacao);

    /*
     * Retirar -1 no total de passageiros da estação escolhida.
     *  provavelmente usar Structs para as estações disponiveis MAX 5
    */

    totalPassageiros[estacao][1] = totalPassageiros[estacao][1] + 1;

}

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
        if (pa[i]->horarioEntrada < inicioIntervalo && pa[i]->horarioSaida > fimIntervalo){
            infHEntrada = localtime(&pa[i]->horarioEntrada);
            infHSaida = localtime(&pa[i]->horarioSaida);
            fprintf(arquivo, "------------------------\n");
            fprintf(arquivo, "ID do Cartão: %d\n", pa[i]->idCartao);
            fprintf(arquivo, "Nome: %d\n", pa[i]->nomePassageiro);
            fprintf("Horario saída: %02d:%02d:%02d\n",
                    infHEntrada->tm_hour, infHEntrada->tm_min, infHEntrada->tm_sec);
            fprintf(arquivo, "Horario de saida: %.d\n", pa[i]->horarioSaida);
            fprintf(arquivo, "Estação de entrada: %.d\n", pa[i]->estacaoEntrada);
            fprintf(arquivo, "Estação de Saida: %.d\n", pa[i]->estacaoSaida);
            fprintf(arquivo, "------------------------\n");
        }
    }



    // Fechar o arquivo
    fclose(arquivo);

    printf("Relatório gerado com sucesso e salvo em %s.\n", nomeArquivo);
}

void visualizarFluxoEstacao( int estacao){

}
