//
// Created by Xtreme Pc on 4/11/2024.
//

#ifndef OOP_LISTATURNEE_H
#define OOP_LISTATURNEE_H

#include <iostream>
#include <utility>
#include <vector>
#include "Turneu.h"

class ListaTurnee {
private:
    std::vector<Turneu> listaturnee;

public:
    //[[maybe_unused]] explicit ListaTurnee(std::string nume){ this->nume=std::move(nume);}
    ListaTurnee()=default;
    ~ListaTurnee()=default;
    std::vector<Turneu>& get_lista();


    unsigned int get_nr_turnee();

    void afisare_lista() const;

    void adaugare_turneu();

    void eliminare_turneu();

    void cautare_turneu_nume() const;

    void citeste_si_afiseaza_n_turnee();
};


#endif //OOP_LISTATURNEE_H
