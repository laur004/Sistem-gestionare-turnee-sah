//
// Created by Xtreme Pc on 4/11/2024.
//
#include "Administrator.h"
#include "ListaTurnee.h"

void Administrator::creareTurneu(ListaTurnee& listaTurnee){
    listaTurnee.adaugare_turneu();
}
void Administrator::eliminareTurneu(ListaTurnee& listaTurnee){
    listaTurnee.eliminare_turneu();
}

void Administrator::adaugareJucator(Turneu &turneu){
    try{
        turneu.adauga_jucator();
        std::cout << "Jucatorul a fost adaugat cu succes.\n";}
    catch(const NrMaximJucatoriAtinsException& e){
        std::cout << "Eroare: " << e.what() << std::endl;
        std::cout << "Doresti sa mai aloci un loc pentru acest jucator? Apasa tasta 1 pentru a aloca.\n";
        int optiune;
        std::cin >> optiune;
        if (optiune == 1){
            turneu.set_NrMaximJucatori(turneu.get_NrMaximJucatori()+1);
            turneu.set_nrrunde();
            turneu.adauga_jucator();
        }
    }
}
void Administrator::eliminareJucator(Turneu &turneu){
    turneu.elimina_jucator();
}

void Administrator::trimiteCerere(Turneu &turneu){
    turneu.adauga_cerere();
}