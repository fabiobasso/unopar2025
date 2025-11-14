
// principal.c

#include<stdio.h>
#include"utilidades.h"
#include "roger.h"

int main(){
    printf("Hello\n");

    get_motherboard_model();

    char serial[MAX_SERIAL_LEN];

    printf("Tentando obter o numero de serie do HD...\n");

    if (get_hd_serial_number(serial, sizeof(serial)) == 0) {
        printf("Numero de Serie do HD: %s\n", serial);
    } else {
        printf("ERRO: Nao foi possível obter o numero de série do HD. Resultado: %s\n", serial);
        printf("Dica: No Linux, pode ser necessario executar como 'sudo' (superusuario).\n");
    }

    return 0;
}

