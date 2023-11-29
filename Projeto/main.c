#include <stdio.h>
#include <time.h>
const int MAX_ITEM = 20;
int contPassageiro = 0;
int totalPassageiros[5][2]; //Uma matriz para guardar a estação como posição (de 1 a 5) e a quantidade de passageiros, sendo a primeira posição as entradas e a segunda a saida



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

//Passageiro passageiros[MAX_ITEM];

void cadastroPassageiro();

void registrarEntrada(Passageiro* passageiros, int estacaoEntrada);

void registrarSaida(Passageiro* passageiros, int estacaoSaida);

void gerarRelatorio(Passageiro* passageiros, time_t inicioIntervalo, time_t fimIntervalo, const char *nomeArquivo);

void visualizarFluxoEstacao(Passageiro* passageiros, int estacao);

int main() {
    /**
     * Menu do projeto de passagem
     * deve conter
     */
    int opc = -1;
    time_t time(time_t *inicioIntervalo);
    const char *nomeArquivo = "relatorio.txt";

    struct tm intervaloI;
    struct tm intervaloF;

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

        switch (opc) {
            case 1:
                //registrar entrada


                //registrarEntrada(passageiros[contPassageiros], estacao)
                break;
            case 2:
                //registrar saida
                break;
            case 3:
                //gerar relatorio
                printf("Digite o inicio do intervalo que deseja gerar o relatorio \n");
                scanf("%d:%d:%d", &intervaloI.tm_hour, &intervaloI.tm_min, &intervaloI.tm_sec);

                printf("Digite o fim do intervalo que deseja gerar o relatorio \n");
                scanf("%d:%d:%d", &intervaloF.tm_hour, &intervaloF.tm_min, &intervaloF.tm_sec);

                time_t inicioIntervalo = mktime(&intervaloI);
                time_t fimIntervalo = mktime(&intervaloF);

                //gerarRelatorio(passageiros[idCartao],totalPassageiros ,inicioIntervalo, fimIntervalo);

                break;
            case 4:
                //fluxo de estação
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

void registrarEntrada(Passageiro* passageiros, int estacaoEntrada){
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

    totalPassageiros[estacao][0] = totalPassageiros[estacao][0] + 1;
}

void registrarSaida(Passageiro* passageiros, int estacaoSaida){
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

    /*
     * Retirar -1 no total de passageiros da estação escolhida.
     *  provavelmente usar Structs para as estações disponiveis MAX 5
    */

    totalPassageiros[estacao][1] = totalPassageiros[estacao][1] + 1;

}

void gerarRelatorio(Passageiro* passageiros, time_t inicioIntervalo, time_t fimIntervalo, const char *nomeArquivo){
    // Abrir o arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo, "w");
    Passageiro passageiro[MAX_ITEM];


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
    for (int i = 0; i < contPassageiro; i++) {
        if (passageiro[i].horarioEntrada < inicioIntervalo && passageiro[i].horarioSaida > fimIntervalo){
            fprintf(arquivo, "------------------------\n");
            fprintf(arquivo, "ID do Cartão: %d\n", passageiro[i].idCartao);
            fprintf(arquivo, "Nome: %d\n", passageiro[i].nomePassageiro);
            fprintf(arquivo, "Horario de entrada: %.d\n", passageiro[i].horarioEntrada);
            fprintf(arquivo, "Horario de saida: %.d\n", passageiro[i].horarioSaida);
            fprintf(arquivo, "Estação de entrada: %.d\n", passageiro[i].estacaoEntrada);
            fprintf(arquivo, "Estação de Saida: %.d\n", passageiro[i].estacaoSaida);
            fprintf(arquivo, "------------------------\n");
        }
    }

    

    // Fechar o arquivo
    fclose(arquivo);

    printf("Relatório gerado com sucesso e salvo em %s.\n", nomeArquivo);
}

void visualizarFluxoEstacao(Passageiro* passageiros, int estacao){

}
