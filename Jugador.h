#pragma once
#define JUGADOR_H

struct Jugador {
    int x;
    int y;
    int vidas = 3;
    int oro = 0;
    float bonificacion = 0.0f;
}