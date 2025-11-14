
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_motherboard_model() {
    FILE *fp;
    char output[1024];
    // Comando para obter o fabricante e o produto (modelo) da placa-mãe
    const char *command = "wmic baseboard get manufacturer,product";

    // Abre o pipe para executar o comando e ler a saída
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Falha ao executar o comando\n");
        return;
    }

    // Lê a saída linha por linha
    printf("Informacoes da Placa-mae:\n");
    while (fgets(output, sizeof(output), fp) != NULL) {
        // Imprime a saída (você precisaria de parsing mais sofisticado para extrair apenas o modelo)
        printf("%s", output);
    }

    // Fecha o pipe
    pclose(fp);
}



