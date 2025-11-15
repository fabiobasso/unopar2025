//vitor.c

#include <stdio.h>
#include <windows.h>
#include "vitor.h"

void mostrarInfoDisco(const char *caminho) {
    ULARGE_INTEGER espacoLivre, espacoTotal, espacoLivreUsuario;

    if (GetDiskFreeSpaceEx(caminho, &espacoLivreUsuario, &espacoTotal, &espacoLivre)) {
        printf("=== Informações do disco %s ===\n", caminho);

        printf("Tamanho total do disco : %.2f GB\n",
               (double)espacoTotal.QuadPart / (1024 * 1024 * 1024));

        printf("Espaço livre           : %.2f GB\n",
               (double)espacoLivre.QuadPart / (1024 * 1024 * 1024));

        printf("Espaço disponível      : %.2f GB\n",
               (double)espacoLivreUsuario.QuadPart / (1024 * 1024 * 1024));
    }
    else {
        printf("Erro ao acessar o disco %s\n", caminho);
    }
}

