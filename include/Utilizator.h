//
// Created by Xtreme Pc on 4/11/2024.
//

#ifndef OOP_UTILIZATOR_H
#define OOP_UTILIZATOR_H
#include <iostream>
#include "ListaTurnee.h"

class Utilizator{

public:
    virtual void trimiteCerere(Turneu& turneu)=0;
    virtual ~Utilizator()=default;

};


#endif //OOP_UTILIZATOR_H
