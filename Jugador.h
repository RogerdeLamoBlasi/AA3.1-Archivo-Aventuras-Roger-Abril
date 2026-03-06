#pragma once
#include <vector>

struct Jugador {

    int x;
    int y;
    int vidas = 3;
    int oro = 0;
    float bonificacion = 0.0;

    void moverJugador(char entrada, std::vector<std::vector<char>>& mapa);
};