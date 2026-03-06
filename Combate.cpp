#include "combate.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// Combate entre el jugador y un enemigo. La probabilidad de victoria se basa en una fórmula que incluye una bonificación del jugador.
bool iniciarCombate(Jugador& jugador) {

    float probabilidad = (1.0 / 3.0) + jugador.bonificacion;

    if (probabilidad > 0.9)
        probabilidad = 0.9;

    float tirada = (float)rand() / RAND_MAX;

    std::cout << "\nCOMBATE\n";
    std::cout << "Probabilidad de victoria: " << probabilidad * 100 << "%\n";

    if (tirada <= probabilidad) {
        std::cout << "¡Has ganado el combate!\n";
        return true;
    }
    else {
        jugador.vidas--;

        std::cout << "Has perdido el combate. Vidas restantes: "
            << jugador.vidas << "\n";

        return false;
    }
}

// Comprueba si quedan enemigos en el mapa. Si no quedan, el jugador gana la partida.
bool quedanEnemigos(const std::vector<std::vector<char>>& mapa) {

    for (const auto& fila : mapa) {
        for (char c : fila) {
            if (c == 'E')
                return true;
        }
    }

    return false;
}

// Comprueba si el jugador ha entrado en contacto con un enemigo. Si es así, inicia el combate y actualiza el mapa.
void comprobarEnemigo(std::vector<std::vector<char>>& mapa, Jugador& jugador) {

    if (mapa[jugador.y][jugador.x] == 'E') {

        bool victoria = iniciarCombate(jugador);

        if (victoria) {
            mapa[jugador.y][jugador.x] = '.';
        }

        if (jugador.vidas <= 0) {
            std::cout << "GAME OVER\n";
            exit(0);
        }

        if (!quedanEnemigos(mapa)) {
            std::cout << "¡HAS GANADO LA PARTIDA!\n";
            exit(0);
        }
    }
}