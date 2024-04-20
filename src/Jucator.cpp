//
// Created by Xtreme Pc on 4/11/2024.
//
#include "Jucator.h"

#include <utility>


Jucator::Jucator() : nume("Bye"), prenume(" "), rating(0),puncte(0){}
Jucator::Jucator(std::string nume, std::string prenume, int rating) : nume(std::move(nume)), prenume(std::move(prenume)), rating(rating),puncte(0) {}
[[nodiscard]] std::string Jucator::get_nume()const{return nume;}
[[nodiscard]] std::string Jucator::get_prenume()const{return prenume;}
int Jucator::get_rating() const{return rating;}
void Jucator::set_rating(int nr){rating=nr;}
[[nodiscard]] double Jucator::get_puncte() const{return puncte;}
void Jucator::set_puncte(double x){puncte=x;}
std::ostream &operator<<(std::ostream &out, Jucator& jucator){
    out<<jucator.nume<<" "<<jucator.prenume<<" Rating: "<<jucator.rating<<"; Puncte: "<<jucator.puncte<<std::endl;
    return out;
}
std::istream &operator>>(std::istream &in,Jucator& jucator){
    std::cout<<"Nume: ";
    in>>jucator.nume;
    std::cout<<"Prenume: ";
    in>>jucator.prenume;
    std::cout<<"Rating: ";
    in>>jucator.rating;
    return in;
}

Jucator& Jucator::operator=(const Jucator& jucator){
    this->nume=jucator.nume;
    this->prenume=jucator.prenume;
    if(jucator.rating>=1001)
        this->rating=jucator.rating;
    else
        this->rating=1001;
    this->puncte=jucator.puncte;
    return *this;
}

Jucator::Jucator(std::string nume, std::string prenume, int rating, double puncte): nume(std::move(nume)),prenume(std::move(prenume)),rating(rating),puncte(puncte){}
