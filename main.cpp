#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Jugador.h"
#include "cofres.h"
#include "combate.h"

#define PLAYER 'P'

// El mapa se representa como un vector de vectores de caracteres, donde cada carácter representa un tipo de casilla.
std::vector<std::vector<char>> mapa;
std::string linea;
char entrada;
bool choice;

Jugador jugador;
void baseMapa() {
    std::ifstream archivo("mapaBase.txt");

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo\n";
        exit(0);
    }
    else {

        while (getline(archivo, linea)) {
            mapa.push_back(std::vector<char>(linea.begin(), linea.end()));
        }
    }
    archivo.close();
}
// Cargar el mapa desde un archivo de texto.
void cargarMapa() {

    std::ifstream archivo("mapa.txt");

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo\n";
        exit(0);
    }
    else {

        while (getline(archivo, linea)) {
            mapa.push_back(std::vector<char>(linea.begin(), linea.end()));
        }
    }
    archivo.close();

    jugadorItems(jugador);
}

// Guardar el mapa actualizado en el archivo de texto después de cada movimiento del jugador.
void guardarMapa() {

    std::ofstream archivo("mapa.txt");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo\n";
        exit(0);
    }
    else {
        for (size_t i = 0; i < mapa.size(); i++)
        {
            for (size_t j = 0; j < mapa[i].size(); j++)
            {
                archivo << mapa[i][j];
            }

            archivo << "\n";
        }
        archivo.close();
    }

    guardarItems(jugador);
}

// Mostrar el mapa en la consola para que el jugador pueda ver su posición y el entorno.
void mostrarMapa() {

    std::cout << "Ahora mismo tienes: " << jugador.oro << " monedas de oro\n";
    for (size_t i = 0; i < mapa.size(); i++)
    {
        for (size_t j = 0; j < mapa[i].size(); j++)
        {
            std::cout << mapa[i][j];
        }

        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "bienvenido a archivos y aventuras, quieres cargar la partida o jugar una nueva? (0 / 1) ";
    std::cin >> choice;

    if (choice) {
        baseMapa();
    }
    if (!choice) {
        cargarMapa();
    }

	// Buscar la posición inicial del jugador en el mapa y almacenarla en la estructura Jugador.
    for (int i = 0; i < mapa.size(); i++)
    {
        for (int j = 0; j < mapa[i].size(); j++)
        {
            if (mapa[i][j] == PLAYER) {

                jugador.y = i;
                jugador.x = j;
            }
        }
    }

	// Bucle principal del juego. El jugador puede moverse por el mapa usando las teclas W, A, S, D. Después de cada movimiento, se actualiza el mapa y se muestra al jugador.
    while (true)
    {
        mostrarMapa();

        std::cin >> entrada;

        jugador.moverJugador(entrada, mapa);

        guardarMapa();
        system("cls");
    }
}