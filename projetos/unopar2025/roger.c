// hd_info.c

#include "roger.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    // Para Windows, usamos _popen e _pclose
    #include <stdlib.h>
    #define popen _popen
    #define pclose _pclose
#else
    // Para Linux/POSIX, usamos popen e pclose
    #include <stdlib.h>
#endif

// Definição da função principal
int get_hd_serial_number(char* serial_buffer, size_t buffer_size) {
    FILE *fp = NULL;
    char line[256];
    char command[150];

    // Garantir que o buffer seja grande o suficiente
    if (buffer_size < MAX_SERIAL_LEN) {
        strncpy(serial_buffer, "BUFFER_TOO_SMALL", buffer_size);
        return -1;
    }

    // --- Lógica Específica do Sistema Operacional ---
    #ifdef _WIN32
        // Windows: Usa WMIC para obter o serial do disco físico
        // O comando "/value" é usado para formatar o output.
        snprintf(command, sizeof(command), "wmic diskdrive get SerialNumber /value");
        fp = popen(command, "r");
    #else
        // Linux: Usa hdparm (pode exigir sudo/root)
        // Obtém o serial do primeiro disco SATA/IDE
        snprintf(command, sizeof(command), "sudo hdparm -i /dev/sda 2>/dev/null | grep -i 'Serial No:'");
        fp = popen(command, "r");
    #endif

    if (fp == NULL) {
        perror("Falha ao executar popen/wmipipe");
        strncpy(serial_buffer, "N/A", buffer_size);
        return -1;
    }

    // --- Processamento da Saída ---

    // 1. Ler a saída linha por linha
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *serial_key;

        #ifdef _WIN32
            serial_key = strstr(line, "SerialNumber=");
        #else
            serial_key = strstr(line, "Serial No:");
        #endif

        if (serial_key != NULL) {
            // 2. Encontrar o início do número de série (após o prefixo)
            #ifdef _WIN32
                char *serial_start = serial_key + strlen("SerialNumber=");
            #else
                char *serial_start = serial_key + strlen("Serial No:");
            #endif

            // Pular espaços em branco e tabulações após o prefixo
            while (*serial_start == ' ' || *serial_start == '\t') {
                serial_start++;
            }

            // 3. Encontrar o final e copiar
            char *serial_end = serial_start;
            while (*serial_end != '\0' && *serial_end != '\n' && *serial_end != '\r') {
                serial_end++;
            }
            *serial_end = '\0'; // Terminar a string no final

            // Copiar o serial para o buffer de saída
            strncpy(serial_buffer, serial_start, buffer_size - 1);
            serial_buffer[buffer_size - 1] = '\0';

            pclose(fp);
            return 0; // Sucesso
        }
    }

    pclose(fp);
    strncpy(serial_buffer, "NOT_FOUND", buffer_size);
    return -1; // Falha na extração ou serial não encontrado
}
