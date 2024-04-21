//
// Created by Xtreme Pc on 4/20/2024.
//
#include "Runda.h"

std::vector<Partida>& Runda::get_partide(){return Partide;}
void Runda::afiseaza_runda(){
    for(auto & aux : Partide)
    {std::cout<<aux.get_alb().get_nume()<<" "<<aux.get_alb().get_prenume()<<"  ";
        switch (aux.getRezultat()) {
            case -100:{std::cout<<" - ";
                break;}
            case 1:{std::cout<<" 1-0 ";
                break;}
            case 0:{std::cout<<" 1/2-1/2 ";
                break;}
            case -1:{std::cout<<" 0-1 ";
                break;}
            default:{std::cout<<" - ";
                break;}
        }
        std::cout<<"  "<<aux.get_negru().get_nume()<<" "<<aux.get_negru().get_prenume()<<"\n";

    }


}