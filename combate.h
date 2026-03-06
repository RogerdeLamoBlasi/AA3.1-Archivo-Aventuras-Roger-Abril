#pragma once
#include <vector>
#include <string>
#include "Jugador.h"

bool iniciarCombate(Jugador& jugador);
bool quedanEnemigos(const std::vector<std::vector<char>>& mapa);
void comprobarEnemigo(std::vector<std::vector<char>>& mapa, Jugador& jugador);