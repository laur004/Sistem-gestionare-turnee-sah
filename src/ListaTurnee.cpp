//
// Created by Xtreme Pc on 4/11/2024.
//
#include "ListaTurnee.h"


std::vector<Turneu>& ListaTurnee::get_lista(){
    return listaturnee;
}


unsigned int ListaTurnee::get_nr_turnee(){
    return listaturnee.size();
}
void  ListaTurnee::afisare_lista() const {
    if (listaturnee.empty()) {
        std::cout << "Lista de turnee este goala!\n";
        return;
    }
    std::cout << "\n\nAcestea sunt turneele existente:\n";
    for (size_t i = 0; i < listaturnee.size(); ++i) {
        std::cout << i + 1 << '.'<<listaturnee[i]<<"\n";
    }
}

void ListaTurnee::adaugare_turneu() {
    Turneu turneu_nou;
    std::cin >> turneu_nou;
    bool flag= true;
    for(const auto & turneu : listaturnee)
        if (turneu.get_nume() == turneu_nou.get_nume()) {
            flag = false;
            break;
        }
    if(flag)
    {listaturnee.push_back(turneu_nou);
        std::cout << "Turneu inregistrat cu succes!\n";}
    else
        std::cout<<"Exista deja un turneu identic!\n";


}

void ListaTurnee::eliminare_turneu() {
    if (listaturnee.empty()) {
        std::cout << "Lista de turnee este deja goala!\n";
        return;
    }

    afisare_lista();
    std::cout << "\nIntroduceti indicele turneului pe care vreti sa-l eliminati: ";
    unsigned indice;
    std::cin >> indice;

    if (indice < 1 || indice > listaturnee.size()) {
        std::cout << "Nu exista un turneu cu indicele: " << indice << '\n';
        return;
    }
    std::cout<<"Turneul "<<listaturnee[indice].get_nume()<<" a fost eliminat!\n";
    listaturnee.erase(listaturnee.begin() + indice - 1);

}



void ListaTurnee::cautare_turneu_nume() const {
    std::string sir;
    bool gasit = false;
    std::cout << "\n\nCautati turneu dupa nume: ";
    std::cin >> sir;

    for (const Turneu& turneu : listaturnee) {
        if (turneu.get_nume().find(sir) != std::string::npos) {
            gasit=true;
            std::cout << turneu;
        }
    }

    if (!gasit) std::cout << "Nu s-a gasit un turneu.\n";
}



void ListaTurnee::citeste_si_afiseaza_n_turnee() {
    std::vector<Turneu> turnee;
    unsigned int n;
    std::cout<<"Numar turnee de adaugat sa adaugat: ";
    std::cin>>n;
    for (unsigned int i = 0; i < n; ++i) {
        unsigned int nr_turnee;
        nr_turnee=listaturnee.size();
        std::cout << "Introduceti datele pentru turneul " << i + 1 << ":\n";
        adaugare_turneu();
        if(listaturnee.size()-1==nr_turnee)
            turnee.push_back(listaturnee.back());
        else i--;
    }


    std::cout << "Turneele introduse sunt:\n";
    for (const auto& turneu : turnee) {
        std::cout << turneu << "\n";
    }
}