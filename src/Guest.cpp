//
// Created by Xtreme Pc on 4/11/2024.
//
#include "Guest.h"

void Guest::trimiteCerere(Turneu& turneu) {
    if(turneu.get_NrJucatori()<turneu.get_NrMaximJucatori())
        turneu.adauga_cerere();
    else std::cout<<"Nu se mai pot trimite cereri! Numarul de jucatori pentru acest turneu a fost atins.\n";
}
