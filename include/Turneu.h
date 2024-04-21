//
// Created by Xtreme Pc on 4/11/2024.
//

#ifndef OOP_TURNEU_H
#define OOP_TURNEU_H

#include <iostream>
#include <vector>
#include "Runda.h"

class NrMaximJucatoriAtinsException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class Turneu{
    std::vector<Jucator> listajucatori;
    std::vector<Jucator> Cereri;
    std::vector<Jucator> listaclasament; //asta va fi modificata de fiecare data cand se introduc rezultatele rundelor
    std::vector<Runda> Runde;
    std::string nume;
    //int nrRunde;
    int nrMaximJucatori;
    Jucator bye;
protected:
    int nrRunde;
public:

    //sa fac aici try except: 1)minim 4 jucatori;2)trebuie ca nrmax==nrjuc si sa fac cu catch
    //void StartTurneu();
    virtual void StartTurneu();
    explicit Turneu(std::string nume = "No Name", int nrMaximJucatori = 8);
    virtual ~Turneu()=default;
    std::vector<Runda>& get_listarunde();
    std::vector<Jucator>& get_listajucatori();
    std::vector<Jucator>& get_listaclasament();
    void afiseaza_lista_clasament();
    void afiseaza_lista_cereri();
    void afiseaza_lista_jucatori();
    void ordoneaza_dupa_puncte();
    void ordoneaza_dupa_rating();
    //void set_nume();
    [[nodiscard]] std::string get_nume() const;
    virtual void set_nrrunde();
    [[nodiscard]] int get_nrrunde()const;
    [[nodiscard]] int get_NrJucatori()const;
    void set_NrMaximJucatori(int nr);
    [[nodiscard]] int get_NrMaximJucatori()const;
    void adauga_cerere();
    void accepta_cerere();
    void refuza_cerere();
    void adauga_jucator();
    void elimina_jucator();
    friend std::ostream &operator<<(std::ostream &out, const Turneu& turneu);
    friend std::istream &operator>>(std::istream &in, Turneu& turneu);
};


#endif //OOP_TURNEU_H
