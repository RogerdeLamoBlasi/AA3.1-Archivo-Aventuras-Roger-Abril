#include "cofres.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Cargar los items disponibles en el juego desde un archivo de texto. Cada línea del archivo debe contener el nombre del item y su bonificación.
std::vector<std::pair<std::string, float>> cargarItems() {

    std::vector<std::pair<std::string, float>> items;
    std::ifstream archivo("items.txt");

    if (!archivo.is_open()) {
        std::cout << "Error al abrir items.txt\n";
        return items;
    }

    std::string nombre;
    float bonus;

    while (archivo >> nombre >> bonus) {
        items.push_back({ nombre, bonus });
    }

    archivo.close();
    return items;
}

// Función para abrir un cofre. El jugador recibe una cantidad aleatoria de oro y un item aleatorio que le otorga una bonificación en combate.
void abrirCofre(Jugador& jugador) {

    std::cout << "\nHAS ABIERTO UN COFRE\n";

    int oroGanado = rand() % 91 + 10;
    jugador.oro += oroGanado;

    std::cout << "Has conseguido " << oroGanado << " de oro.\n";
    
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
    std::cout << "Bonificacion de combate +" << bonusItem * 100 << "%\n";
    system("pause");
}

//funcion de guardado de items
void guardarItems(Jugador& jugador) {
    std::ofstream inventario;
    inventario.open("inventario.txt");
    inventario << jugador.bonificacion << std::endl << jugador.oro;
    inventario.close();
}

void jugadorItems(Jugador& jugador) {
    std::ifstream inventario;
    inventario.open("inventario.txt");
    
    int oro;
    float porcentaje;

    if (inventario >> porcentaje >> oro) {
        jugador.bonificacion = porcentaje;
        jugador.oro = oro;
    }

    inventario.close();
}