//
// Created by Xtreme Pc on 4/11/2024.
//

#ifndef OOP_ADMINISTRATOR_H
#define OOP_ADMINISTRATOR_H
#include "ListaTurnee.h"
#include "Utilizator.h"


class Administrator: public Utilizator{
public:

    static void creareTurneu(ListaTurnee& listaTurnee);
    static void eliminareTurneu(ListaTurnee& listaTurnee);
    static void adaugareJucator(Turneu& turneu);
    static void eliminareJucator(Turneu& turneu);
    void trimiteCerere(Turneu &turneu) override;


};


#endif //OOP_ADMINISTRATOR_H
