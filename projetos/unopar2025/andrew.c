#include <iostream>
#include <string>
#include <map>

int main() {
    // Mapeamento simples: nome da placa-mãe → ano de lançamento
    std::map<std::string, int> placaParaAno = {
        {"ASUS P5B", 2006},
        {"Gigabyte GA-970A-DS3", 2011},
        {"MSI B450 Tomahawk", 2018},
        {"ASRock A320M-HD", 2017}
    };

    std::string placa;
    std::cout << "Digite o nome da placa-mae: ";
    std::getline(std::cin, placa);

    // Procura pela placa no mapa
    if (placaParaAno.find(placa) != placaParaAno.end()) {
        std::cout << "A placa-mae \"" << placa
                  << "\" foi lancada no ano de "
                  << placaParaAno[placa] << ".\n";
    } else {
        std::cout << "Placa-mae nao encontrada no banco de dados.\n";
    }

    return 0;
}
