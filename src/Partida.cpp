//
// Created by Xtreme Pc on 4/20/2024.
//
#include "Partida.h"


Partida::Partida(): alb(nullptr), negru(nullptr), rezultat(-100){}
void Partida::set_rezultat(int rez){
    rezultat=rez;
    switch (rezultat) {
        case 1: {alb->set_rating(alb->get_rating()+10);
            negru->set_rating(negru->get_rating()-10);
            alb->set_puncte(alb->get_puncte()+1);
            break;}

        case 0:{alb->set_puncte(alb->get_puncte()+0.5);
            alb->set_puncte(negru->get_puncte()+0.5);
            break;}
        case -1:{alb->set_rating(alb->get_rating()-10);
            negru->set_rating(negru->get_rating()+10);
            break;}
        default:break;

    }
}

[[nodiscard]] int Partida::getRezultat() const{return rezultat;}
void Partida::set_alb(Jucator& jucator){alb=&jucator;}
void Partida::set_negru(Jucator& jucator){negru=&jucator;}
Jucator& Partida::get_alb(){return *alb;}
Jucator& Partida::get_negru(){return *negru;}