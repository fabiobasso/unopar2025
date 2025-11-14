// hd_info.h

#ifndef HD_INFO_H
#define HD_INFO_H

#include <stddef.h>

// Tamanho máximo que o buffer de serial deve ter
#define MAX_SERIAL_LEN 100

/**
 * @brief Obtém o número de série do HD principal.
 * * A implementação real (Windows ou Linux) é selecionada
 * automaticamente durante a compilação.
 * * @param serial_buffer Buffer para armazenar o número de série.
 * @param buffer_size Tamanho do buffer (deve ser >= MAX_SERIAL_LEN).
 * @return int 0 em caso de sucesso, -1 em caso de falha.
 */
int get_hd_serial_number(char* serial_buffer, size_t buffer_size);

#endif // HD_INFO_H
