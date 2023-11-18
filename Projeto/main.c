#include <stdio.h>
#include <time.h>
const int MAX_ITEM = 20;
int contPassageiro = 1;

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

void registrarEntrada(Passageiro* passageiros, int* totalPassageiros, int estacaoEntrada){
    Passageiro passageiro[MAX_ITEM];
    passageiro[contPassageiro].idCartao = contPassageiro;
    printf("Digite o nome do passageiro\n");
    scanf("%s", &passageiro[contPassageiro].nomePassageiro);
    printf("Digite o tempo ")

}
