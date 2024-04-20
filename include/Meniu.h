//
// Created by Xtreme Pc on 4/11/2024.
//

#ifndef OOP_MENIU_H
#define OOP_MENIU_H

#include "Utilizator.h"
#include "ListaTurnee.h"
#include "Administrator.h"
#include "Guest.h"

class Meniu {
public:

    static void aMeniu(Utilizator* utilizator, ListaTurnee& listaTurnee);
    static void MeniuTurneu(Utilizator* utilizator, ListaTurnee& listaTurnee,unsigned int i);
    static void Login( ListaTurnee& listaTurnee);
    static void MeniuCereri(Utilizator* utilizator,ListaTurnee& listaTurnee,unsigned int i);
    static void MeniuRunda(Utilizator* utilizator,ListaTurnee& listaTurnee,unsigned int i, int j);
    static void MeniuListaStart(Utilizator* utilizator,ListaTurnee& listaTurnee,unsigned int i);
};


#endif //OOP_MENIU_H
