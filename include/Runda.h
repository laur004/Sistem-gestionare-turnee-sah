//
// Created by Xtreme Pc on 4/20/2024.
//

#ifndef OOP_RUNDA_H
#define OOP_RUNDA_H

#include "Partida.h"
#include <vector>

class Runda{
    std::vector<Partida> Partide;
public:
    std::vector<Partida>& get_partide();
    void afiseaza_runda();

};

#endif //OOP_RUNDA_H
