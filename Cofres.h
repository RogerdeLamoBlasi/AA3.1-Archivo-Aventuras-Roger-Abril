#pragma 
#define COFRES_H

#include <vector>
#include <string>
#include "Jugador.h"   

void abrirCofre(Jugador& jugador);
std::vector<std::pair<std::string, float>> cargarItems();
void guardarItems(Jugador& jugador);
void jugadorItems(Jugador& jugador);