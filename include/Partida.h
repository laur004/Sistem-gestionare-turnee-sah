//
// Created by Xtreme Pc on 4/20/2024.
//

#ifndef OOP_PARTIDA_H
#define OOP_PARTIDA_H

#include "Jucator.h"

class Partida{
    Jucator* alb;
    Jucator* negru;
    int rezultat;
public:
    Partida();
    void set_rezultat(int rez);
    [[nodiscard]] int getRezultat() const;
    void set_alb(Jucator& jucator);
    void set_negru(Jucator& jucator);
    Jucator& get_alb();
    Jucator& get_negru();

};

#endif //OOP_PARTIDA_H
