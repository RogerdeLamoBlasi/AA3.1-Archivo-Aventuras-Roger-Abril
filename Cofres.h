#pragma once
#ifndef COFRES_H
#define COFRES_H

#include <vector>
#include <string>

void abrirCofre(Jugador& jugador);

std::vector<std::pair<std::string, float>> cargarItems();
