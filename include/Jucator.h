//
// Created by Xtreme Pc on 4/11/2024.
//

#ifndef OOP_JUCATOR_H
#define OOP_JUCATOR_H

#include <iostream>

class Jucator{
    std::string nume;
    std::string prenume;
    int rating;
    double puncte;
public:
    Jucator();
    Jucator(std::string nume, std::string prenume, int rating);
    [[nodiscard]] std::string get_nume()const;
    [[nodiscard]] std::string get_prenume()const;
    [[nodiscard]] int get_rating()const;
    void set_rating(int nr);
    friend std::ostream &operator<<(std::ostream &out, Jucator& jucator);
    friend std::istream &operator>>(std::istream &in,Jucator& jucator);
    Jucator& operator=(const Jucator& jucator);
    [[nodiscard]] double get_puncte() const;
    void set_puncte(double x);
    Jucator(std::string nume, std::string prenume, int rating, double puncte);
    Jucator(const Jucator& other)=default;

};

#endif //OOP_JUCATOR_H
