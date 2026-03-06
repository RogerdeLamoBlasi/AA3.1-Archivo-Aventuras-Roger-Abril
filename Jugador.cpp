#include "Jugador.h"
#include "cofres.h"
#include "combate.h"
#include <iostream>
#define PLAYER 'P'

//comprobar lo que hay en la casilla a la que se ha movido el jugador
void comprobarCasilla(std::vector<std::vector<char>>& mapa, Jugador& jugador) {

    switch (mapa[jugador.y][jugador.x]) {

    case 'C':
        abrirCofre(jugador);
        mapa[jugador.y][jugador.x] = '.';
        break;

    case 'E':
        comprobarEnemigo(mapa, jugador);
        break;

    case '.':
        break;
    }
}

//mover al jugador por el mapa según la entrada del usuario y comprobar si se puede mover a esa casilla
void Jugador::moverJugador(char entrada, std::vector<std::vector<char>>& mapa) {

    int nuevaX = x;
    int nuevaY = y;

    switch (entrada) {

    case 'W':
        nuevaY--;
        break;

    case 'A':
        nuevaX--;
        break;

    case 'S':
        nuevaY++;
        break;

    case 'D':
        nuevaX++;
        break;
    }

    if (mapa[nuevaY][nuevaX] != '#') {

        mapa[y][x] = '.';

        x = nuevaX;
        y = nuevaY;

        comprobarCasilla(mapa, *this);

        mapa[y][x] = PLAYER;
    }
}