#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct Jugador {
    int x;
    int y;
    int vidas = 3;
    int oro = 0;
    float bonificacion = 0.0;
};

bool iniciarCombate(Jugador & jugador) {
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
        std::cout << "Has perdido el combate vaya BOT. Vidas restantes: "
            << jugador.vidas << "\n";
        return false;
    }
}

bool quedanEnemigos(const std::vector<std::string>& mapa) {
    for (const auto& fila : mapa) {
        for (char c : fila) {
            if (c == 'E')
                return true;
        }
    }
    return false;
}

void comprobarEnemigo(std::vector<std::string>& mapa, Jugador& jugador) {
    if (mapa[jugador.y][jugador.x] == 'E') {

        bool victoria = iniciarCombate(jugador);

        if (victoria) {
            mapa[jugador.y][jugador.x] = '.';
        }

        if (jugador.vidas <= 0) {
            std::cout << "GAME OVER BOT\n";
            exit(0);
        }

        if (!quedanEnemigos(mapa)) {
            std::cout << "¡HAS GANADO LA PARTIDA! HELL YEAHHHHHHHH\n";
            exit(0);
        }
    }
}