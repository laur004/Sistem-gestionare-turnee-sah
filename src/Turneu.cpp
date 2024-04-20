//
// Created by Xtreme Pc on 4/11/2024.
//

#include "Turneu.h"
#include <algorithm>

void Turneu::StartTurneu(){
    set_nrrunde();
    for (const Jucator& jucator : listajucatori) {

        Jucator jucatorCopie(jucator.get_nume(), jucator.get_prenume(), jucator.get_rating(),jucator.get_puncte());
        listaclasament.push_back(jucatorCopie);
    }

    Runde.resize(nrRunde);
    bool culoareAlba = true;
    std::vector<Jucator>& jucatoriRotiti = listaclasament;
    if(listajucatori.size()%2) {
        for (size_t aux1 = 0;aux1 < Runde.size(); aux1++) {
            Runde[aux1].get_partide().resize(nrMaximJucatori / 2 + 1);
            if (aux1 != Runde.size() - 1) {
                for (int aux2 = 0; aux2 < nrMaximJucatori / 2; aux2++)
                    if (culoareAlba) {
                        Runde[aux1].get_partide()[aux2].set_alb(jucatoriRotiti[0 + aux2]);
                        Runde[aux1].get_partide()[aux2].set_negru(jucatoriRotiti[jucatoriRotiti.size() - aux2 - 1]);
                    } else {
                        Runde[aux1].get_partide()[aux2].set_negru(jucatoriRotiti[0 + aux2]);
                        Runde[aux1].get_partide()[aux2].set_alb(jucatoriRotiti[jucatoriRotiti.size() - aux2 - 1]);
                    }
                Runde[aux1].get_partide()[nrMaximJucatori / 2].set_alb(jucatoriRotiti[nrMaximJucatori / 2]);
                //Jucator bye;
                Runde[aux1].get_partide()[nrMaximJucatori / 2].set_negru(bye);
                Runde[aux1].get_partide()[nrMaximJucatori / 2].set_rezultat(1);
                std::rotate(jucatoriRotiti.begin() + 1, jucatoriRotiti.begin() + 2, jucatoriRotiti.end());

            }
            else{
                Runde[aux1].get_partide()[nrMaximJucatori / 2].set_alb(jucatoriRotiti[0]);
                //Jucator bye;
                Runde[aux1].get_partide()[nrMaximJucatori / 2].set_negru(bye);
                Runde[aux1].get_partide()[nrMaximJucatori / 2].set_rezultat(1);
                for (int aux2 = 1; aux2 <= nrMaximJucatori / 2; aux2++)
                    if (culoareAlba) {
                        Runde[aux1].get_partide()[aux2-1].set_alb(jucatoriRotiti[0 + aux2]);
                        Runde[aux1].get_partide()[aux2-1].set_negru(jucatoriRotiti[jucatoriRotiti.size() - aux2]);
                    } else {
                        Runde[aux1].get_partide()[aux2-1].set_negru(jucatoriRotiti[0 + aux2]);
                        Runde[aux1].get_partide()[aux2-1].set_alb(jucatoriRotiti[jucatoriRotiti.size() - aux2]);
                    }

            }
            culoareAlba=!culoareAlba;}
    }

    else {
        for (auto & aux1 : Runde) {
            aux1.get_partide().resize(nrMaximJucatori / 2);

            for (int aux2 = 0; aux2 < nrMaximJucatori / 2; aux2++)
                if (culoareAlba) {
                    aux1.get_partide()[aux2].set_alb(jucatoriRotiti[aux2]);
                    aux1.get_partide()[aux2].set_negru(jucatoriRotiti[jucatoriRotiti.size() - aux2 - 1]);
                } else {
                    aux1.get_partide()[aux2].set_negru(jucatoriRotiti[aux2]);
                    aux1.get_partide()[aux2].set_alb(jucatoriRotiti[jucatoriRotiti.size() - aux2 - 1]);
                }


            culoareAlba=!culoareAlba;
        }
    }
}

Turneu::Turneu(std::string nume, int nrMaximJucatori) : nume(std::move(nume)), nrMaximJucatori(nrMaximJucatori), nrRunde(nrMaximJucatori - 1) {}
std::vector<Runda>& Turneu::get_listarunde(){return Runde;}
std::vector<Jucator>& Turneu::get_listajucatori(){return listajucatori;}
std::vector<Jucator>& Turneu::get_listaclasament(){return listaclasament;}
void Turneu::afiseaza_lista_cereri() {
    std::cout<<"Acestea sunt cererile:\n\n";
    for (size_t i = 0; i < Cereri.size(); ++i) {
        std::cout<<i+1<<"."<<Cereri[i]<<"\n";}
}

void Turneu::afiseaza_lista_clasament(){std::cout<<"Aceasta este clasamentul turneului "<<nume<<": \n";
    for (size_t i = 0; i < listajucatori.size(); ++i) {
        std::cout<<i+1<<"."<<listaclasament[i]<<"\n";}
}


void Turneu::afiseaza_lista_jucatori(){std::cout<<"Aceasta este lista turneului "<<nume<<": \n";
    for (size_t i = 0; i < listajucatori.size(); ++i) {
        std::cout<<i+1<<"."<<listajucatori[i]<<"\n";}
}

void Turneu::ordoneaza_dupa_puncte(){
    std::sort(get_listaclasament().begin(),get_listaclasament().end(), [](const Jucator& a, const Jucator& b) {
        return b.get_puncte() < a.get_puncte();
    });
}

void Turneu::ordoneaza_dupa_rating(){
    std::sort(get_listajucatori().begin(),get_listajucatori().end(), [](const Jucator& a, const Jucator& b) {
        return b.get_rating() < a.get_rating();
    });
}


[[nodiscard]] std::string Turneu::get_nume() const{return nume;}
void Turneu::set_nrrunde(){ nrRunde=nrMaximJucatori%2?nrMaximJucatori : nrMaximJucatori-1;}
int Turneu::get_nrrunde() const{return nrRunde;}
void Turneu::set_NrMaximJucatori(int nr){nrMaximJucatori=nr;}
int Turneu::get_NrMaximJucatori() const{return nrMaximJucatori;}


void Turneu::adauga_cerere(){
    std::cout<<"Completeaza formularul de inscriere:\n";
    Jucator jucator;
    std::cin>>jucator;
    Cereri.push_back(jucator);
    std::cout<<"Cerere trimisa cu succes!\n";
}
void Turneu::accepta_cerere() {
    afiseaza_lista_cereri();
    std::cout<<"Introdu indicele cererii pe care vrei sa o accepti: ";
    unsigned int i;
    std::cin>>i;
    if(i<1 || i>Cereri.size()) std::cout<<"Nu exista cererea cu indicele "<<i<<std::endl;
    else {
        if (nrMaximJucatori <= get_NrJucatori()){
            std::cout << "Numar de jucatori atins! Apasa 1 daca vrei sa accepti cererea: ";
            int aux;
            std::cin >> aux;
            if (aux == 1) {
                nrMaximJucatori++;
                listajucatori.push_back(Cereri[i - 1]);
                ordoneaza_dupa_rating();
                Cereri.erase(Cereri.begin() + i - 1);
                set_nrrunde();
            }
        } else {
            listajucatori.push_back(Cereri[i - 1]);
            ordoneaza_dupa_rating();
            Cereri.erase(Cereri.begin() + i - 1);
        }
    }
}

void Turneu::refuza_cerere() {
    afiseaza_lista_cereri();
    std::cout<<"Introdu indicele cererii pe care vreti sa o refuzati: ";
    unsigned int i;
    std::cin>>i;
    if(i<1 || i>Cereri.size()) std::cout<<"Nu exista cererea cu indicele "<<i<<std::endl;
    else{
        listajucatori.push_back(Cereri[i-1]);
        Cereri.erase(Cereri.begin()+i-1);}
}



[[nodiscard]] const char* NrMaximJucatoriAtinsException::what() const noexcept{return "Numarul maxim de jucatori a fost atins!\n";}

void Turneu::adauga_jucator(){
    if(nrMaximJucatori>get_NrJucatori()) {
        std::cout << "Introdu datele pentru inregistrare: \n";
        Jucator jucator;
        std::cin >> jucator;
        listajucatori.push_back(jucator);
        ordoneaza_dupa_rating();
    }
    else
        throw NrMaximJucatoriAtinsException();
}




int Turneu::get_NrJucatori() const{
    return (int)listajucatori.size();
}

void Turneu::elimina_jucator(){
    if (listajucatori.empty()) {
        std::cout << "Lista de jucatori este deja goala!\n";
        return;
    }

    afiseaza_lista_jucatori();
    std::cout << "\nIntroduceti indicele jucatorului pe care vreti sa-l eliminati: ";
    unsigned indice;
    std::cin >> indice;

    if (indice < 1 || indice > listajucatori.size()) {
        std::cout << "Nu exista un jucator cu indicele: " << indice << '\n';
        return;
    }
    std::cout<<"Jucatorul "<<listajucatori[indice-1].get_nume()<<" "<<listajucatori[indice-1].get_prenume()<<" Rating: "<<listajucatori[indice-1].get_rating()<<" a fost eliminat"<<std::endl;
    listajucatori.erase(listajucatori.begin() + indice - 1);

}

std::ostream &operator<<(std::ostream &out, const Turneu& turneu){
    //pentru ca am declarat const nu pot avea acces direct la membrii care sunt non-const
    out<<"Nume: "<<turneu.get_nume()<<"; NrRunde: "<<turneu.get_nrrunde()<<"; NrJucatori: "<<turneu.get_NrJucatori()<<"\\"<<turneu.get_NrMaximJucatori()<<std::endl;
    return out;
}
std::istream &operator>>(std::istream &in,Turneu& turneu){
    std::cout<<"Nume turneu: ";
    in>>turneu.nume;
    std::cout<<"Numar jucatori: ";
    in>>turneu.nrMaximJucatori;
    turneu.set_nrrunde();
    return in;
}
