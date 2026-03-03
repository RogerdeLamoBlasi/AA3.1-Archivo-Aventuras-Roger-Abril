#include "cofres.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

std::vector<std::pair<std::string, float>> cargarItems() {

    std::vector<std::pair<std::string, float>> items;
    std::ifstream file("items.txt");

    if (!file.is_open()) {
        std::cout << "Error al abrir items.txt\n";
        return items;
    }

    std::string nombre;
    float bonus;

    while (file >> nombre >> bonus) {
        items.push_back({ nombre, bonus });
    }

    file.close();
    return items;
}

void abrirCofre(Jugador& jugador) {

    std::cout << "\nHAS ABIERTO UN COFRE\n";

	//oro aleatorio
    int oroGanado = rand() % 91 + 10; // 10-100
    jugador.oro += oroGanado;

    std::cout << "Has conseguido " << oroGanado << " de oro.\n";

	//items aleatorios
    std::vector<std::pair<std::string, float>> items = cargarItems();

    if (items.empty()) {
        std::cout << "No hay items disponibles.\n";
        return;
    }
    int indice = rand() % items.size();

    std::string nombreItem = items[indice].first;
    float bonusItem = items[indice].second;

    jugador.bonificacion += bonusItem;

    std::cout << "Has conseguido el objeto: " << nombreItem << "\n";
    std::cout << "Bonificacion de combate +"
        << bonusItem * 100 << "%\n";
}