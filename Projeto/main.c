#include <stdio.h>
#include <time.h>
const int MAX_ITEM = 20;
int contPassageiro = 0;


/**
 * Elemento Struct
 */

typedef struct {
    int idCartao;
    char nomePassageiro[100];
    time_t horarioEntrada;
    time_t horarioSaida;
    int estacaoEntrada;
    int estacaoSaida;
} Passageiro;

void cadastroPassageiro();

void registrarEntrada(Passageiro* passageiros, int* totalPassageiros, int estacaoEntrada);

void registrarSaida(Passageiro* passageiros, int totalPassageiros, int estacaoSaida);

void gerarRelatorio(Passageiro* passageiros, int totalPassageiros, time_t inicioIntervalo, time_t fimIntervalo);

void visualizarFluxoEstacao(Passageiro* passageiros, int totalPassageiros, int estacao);

int main() {
    /**
     * Menu do projeto de passagem
     * deve conter
     */
    int opc = -1;
    time_t inicioIntervalo, fimIntervalo;
    time_t time(time_t *inicioIntervalo);

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

        switch (opc) {
            case 1:
                break;
            case 2:
                break;
            case 3:


                break;
            case 4:
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

void cadastroPassageiro(){
    Passageiro passageiro[MAX_ITEM];
    passageiro[contPassageiro].idCartao = contPassageiro;
    printf("Digite o nome do passageiro: \n");
    puts(passageiro[contPassageiro].nomePassageiro);
    contPassageiro++;
}

void registrarEntrada(Passageiro* passageiros, int* totalPassageiros, int estacaoEntrada){
    Passageiro passageiro[MAX_ITEM];
    int idCartao = 0;
    int estacao;

    printf("Escolha o ID do passageiro que deseja: \n");
    scanf("%d", &idCartao);

    if (idCartao < 0 && idCartao > contPassageiro){
        printf("ID não encontrado.\n");
        printf("Cadastrando novo passageiro...\n");
        cadastroPassageiro();
        idCartao = contPassageiro;

        return; //Para fazer: um metodo de perguntar no caso de criar um novo Passageiro ou digitar um novo numero
    }else{
        idCartao = contPassageiro;
    }

    struct tm tempoEntrada;

    printf("\nInsira o horário de entrada (HH:MM:SS): ");
    scanf("%d:%d:%d", &tempoEntrada.tm_hour, &tempoEntrada.tm_min, &tempoEntrada.tm_sec);

    passageiro[idCartao].horarioEntrada = mktime(&tempoEntrada);

    printf("\nInsira o numero da estação de entrada");
    scanf("%d", &estacao);

    /*
     * Adicionar +1 no total de passageiros da estação escolhida.
     *  provavelmente usar Structs para as estações disponiveis MAX 5
    */
}

void registrarSaida(Passageiro* passageiros, int totalPassageiros, int estacaoSaida){
    Passageiro passageiro[MAX_ITEM];
    int idCartao = 0;
    int estacao;

    printf("Escolha o ID do passageiro que deseja: \n");
    scanf("%d", &idCartao);

    if (idCartao < 0 && idCartao > contPassageiro){
        printf("ID não encontrado.\n");
        printf("Cadastrando novo passageiro...\n");
        cadastroPassageiro();
        idCartao = contPassageiro;

        return; //Para fazer: um metodo de perguntar no caso de criar um novo Passageiro ou digitar um novo numero
    }else{
        idCartao = contPassageiro;
    }

    struct tm tempoSaida;

    printf("\nInsira o horário de saida (HH:MM:SS): ");
    scanf("%d:%d:%d", &tempoSaida.tm_hour, &tempoSaida.tm_min, &tempoSaida.tm_sec);

    time_t t1 = mktime(&tempoSaida);
    time_t t2 = passageiro[idCartao].horarioEntrada;

    if (t1 < t2){
        printf("Tempo de saida invalido, tempo de saida antes de passageiro entrar\n");
        return;
    }

    passageiro[idCartao].horarioSaida = t1;

    printf("\nInsira o numero da estação de saida do metro.");
    scanf("%d", &estacao);

}