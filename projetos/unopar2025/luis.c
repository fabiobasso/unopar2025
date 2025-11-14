#include <stdio.h>
#include <time.h>

int data_hora() {
    // 1. Obter o tempo atual (em segundos desde a Epoch)
    time_t tempo_segundos = time(NULL);

    // 2. Converter para hora local
    struct tm *info_tempo = localtime(&tempo_segundos);

    // 3. Acessar os componentes separadamente
    // Dia do mês (1-31)
    int dia = info_tempo->tm_mday;
    // Mês (0-11, onde 0 é Janeiro)
    int mes = info_tempo->tm_mon + 1;
    // Ano (desde 1900)
    int ano = info_tempo->tm_year + 1900;
    // Hora (0-23)
    int hora = info_tempo->tm_hour;
    // Minuto (0-59)
    int minuto = info_tempo->tm_min;
    // Segundo (0-59)
    int segundo = info_tempo->tm_sec;

    // 4. Imprimir a data e hora
    printf("Data e Hora atuais: %02d/%02d/%d %02d:%02d:%02d\n", dia, mes, ano, hora, minuto, segundo);

    return 0;
}
