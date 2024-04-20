//
// Created by Xtreme Pc on 4/11/2024.
//

#ifndef OOP_GUEST_H
#define OOP_GUEST_H
#include <iostream>
#include "Utilizator.h"

class Guest: public Utilizator{
public:
    void trimiteCerere(Turneu& turneu) override;
};


#endif //OOP_GUEST_H
