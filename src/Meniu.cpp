#include <iostream>
#include "Utilizator.h"
#include "ListaTurnee.h"
#include "Meniu.h"

void Meniu::Login(ListaTurnee &listaTurnee) {
    std::cout << "Bine ai venit!\nVrei sa continui ca 1) 'Guest' sau 2) 'Administrator'?\n\nVrei sa iesi? Tasteaza 0\nTasteaza alegerea: ";
    int optiune;
    std::cin >> optiune;
    switch (optiune) {
        case 2: {
            std::cout << "Parola: ";
            std::string parola;
            std::cin >> parola;
            if (parola == "parola") {

                std::cout << "Bine ai venit, admin!\n";
                Administrator admin;
                aMeniu(&admin,listaTurnee); // Apelăm MeniuAdmin() cu obiectul de tip Administrator
            } else {
                std::cout << "Parola incorecta!\n";
                Login( listaTurnee);
            }
            break;
        }

        case 1: {
            Guest guest; // Creăm un obiect de tip Guest
            std::cout << "Bine ai venit, guest!\n";
            aMeniu(&guest,listaTurnee); // Apelăm Meniu() cu obiectul de tip Guest
            break;
        }

        case 0:break;

        default: {
            std::cout << "Nu exista optiunea!\n";
            Login(listaTurnee);
            break;
        }
    }
}

void Meniu::aMeniu(Utilizator* utilizator,ListaTurnee& listaTurnee){
    std::cout<<"0)Inapoi\n";
    if(dynamic_cast<Administrator*>(utilizator)) {

        std::cout << "1)Creeaza turneu\n";
        std::cout << "2)Creaza n turnee\n";
        std::cout << "3)Elimina turneu\n";
        std::cout << "4)Selecteaza turneu\n";
        std::cout << "5)Cauta turneu\n";

        std::cout<<"\n\n";
        listaTurnee.afisare_lista();

        std::cout<<"\n\nSelecteaza optiunea: ";
        int optiune;
        std::cin>>optiune;
        switch (optiune) {
            case 0:{
                Login(listaTurnee);
                break;}
            case 1: {Administrator::creareTurneu(listaTurnee);
                aMeniu(utilizator,listaTurnee);
                break;}

            case 2:{
                listaTurnee.citeste_si_afiseaza_n_turnee();
                aMeniu(utilizator,listaTurnee);
                break;
            }
            case 3:{Administrator::eliminareTurneu(listaTurnee);
                aMeniu(utilizator,listaTurnee);
                break;}
            case 4:{listaTurnee.afisare_lista();
                std::cout << "Introdu indicele turneului: ";
                unsigned int i;
                std::cin >> i;
                if (i < 1 || i > listaTurnee.get_nr_turnee()) {
                    std::cout << "Nu exista turneul cu indicele " << i << "\n";
                    aMeniu(utilizator, listaTurnee);
                } else {
                    MeniuTurneu(utilizator, listaTurnee, i-1);
                }
                break;}

            case 5:{listaTurnee.cautare_turneu_nume();
                aMeniu(utilizator,listaTurnee);
                break;}
            default: aMeniu(utilizator,listaTurnee);

        }



    }
    else if(dynamic_cast<Guest*>(utilizator)){
        std::cout << "1)Selecteaza turneu\n";
        std::cout << "2)Cauta turneu\n";

        std::cout<<"\n\n";
        listaTurnee.afisare_lista();


        std::cout<<"\n\nSelecteaza optiunea: ";

        int optiune;
        std::cin>>optiune;
        switch (optiune) {
            case 0:{Login(listaTurnee);
                break;}
            case 1: {
                listaTurnee.afisare_lista();
                std::cout << "Introdu indicele turneului: ";
                unsigned int i;
                std::cin >> i;
                if (i < 1 || i > listaTurnee.get_nr_turnee()) {
                    std::cout << "Nu exista turneul cu indicele " << i << "\n";
                    aMeniu(utilizator, listaTurnee);
                } else {
                    MeniuTurneu(utilizator, listaTurnee, i-1);
                }
                break;
            }

            case 2: {listaTurnee.cautare_turneu_nume();
                aMeniu(utilizator,listaTurnee);
                break;}
            default:
            {aMeniu(utilizator,listaTurnee);
                break;}

        }


    }



}




//DE REZOLVAT ADAUGARE/ELIMINARE JUCATOR
void Meniu::MeniuTurneu(Utilizator* utilizator,ListaTurnee& listaTurnee, unsigned int i) {
    std::cout << "0)Inapoi\n";
    if (listaTurnee.get_lista()[i].get_listaclasament().empty()) {
        if (dynamic_cast<Administrator *>(utilizator)) {
            // Afișează opțiunile specifice pentru administrator
            std::cout << "1)Adauga jucator\n";
            std::cout << "2)Elimina jucator\n";
            std::cout << "3)Cerere inscriere jucator\n";
            std::cout << "4)Vezi cereri inscriere\n";
            std::cout << "5)Start turneu\n\n";

            listaTurnee.get_lista()[i].afiseaza_lista_jucatori();

            std::cout << "\nSelecteaza optiunea: ";
            int optiune;
            std::cin >> optiune;
            switch (optiune) {
                case 0: {
                    aMeniu(utilizator, listaTurnee);
                    break;
                }
                case 1: {
                    Administrator::adaugareJucator(listaTurnee.get_lista()[i]);
                    MeniuTurneu(utilizator, listaTurnee, i);
                    break;
                }
                case 2: {
                    Administrator::eliminareJucator(listaTurnee.get_lista()[i]);
                    MeniuTurneu(utilizator, listaTurnee, i);
                    break;
                }
                case 3: {
                    utilizator->trimiteCerere(listaTurnee.get_lista()[i]);
                    MeniuTurneu(utilizator, listaTurnee, i);
                    break;
                }
                case 4: {
                    MeniuCereri(utilizator, listaTurnee, i);
                    break;
                }
                case 5:{if(listaTurnee.get_lista()[i].get_NrMaximJucatori()!=listaTurnee.get_lista()[i].get_NrJucatori())
                        std::cout<<"Nu se poate incepe turneul! Nu s-a intrunit numarul de jucatori!\n";
                        else{ listaTurnee.get_lista()[i].StartTurneu();}
                    MeniuTurneu(utilizator, listaTurnee, i);
                    break;
                }
                default: {
                    std::cout << "Nu exista optiunea!";
                    MeniuTurneu(utilizator, listaTurnee, i);
                }

            }


            // Alte opțiuni specifice pentru administrator
        } else if (dynamic_cast<Guest *>(utilizator)) {
            std::cout << "1)Cerere inscriere jucator\n";


            std::cout << "\n\n";
            listaTurnee.get_lista()[i].afiseaza_lista_jucatori();

            std::cout << "Selecteaza optiunea: ";

            int optiune;
            std::cin >> optiune;
            switch (optiune) {
                case 0: {
                    aMeniu(utilizator, listaTurnee);
                    break;
                }
                case 1: {
                    utilizator->trimiteCerere(listaTurnee.get_lista()[i]);
                    MeniuTurneu(utilizator, listaTurnee, i);
                    break;
                }
                default: {
                    MeniuTurneu(utilizator, listaTurnee, i);
                    break;
                }

            }


        }
    } else {

        if (dynamic_cast<Administrator *>(utilizator)) {

            std::cout << "1)Selecteaza runda: ";
            for(int aux=0; aux<listaTurnee.get_lista()[i].get_nrrunde();aux++)
                std::cout<< "R"<<aux+1<<" ";
            std::cout<<"\n";

            std::cout << "2)Vezi lista de start\n\n";

            listaTurnee.get_lista()[i].afiseaza_lista_clasament();

            std::cout << "\nSelecteaza optiunea: ";
            int optiune;
            std::cin >> optiune;
            switch (optiune) {
                case 0: {
                    aMeniu(utilizator, listaTurnee);
                    break;
                }

                case 1:{std::cout<<"Rundele sunt: ";

                    for(int aux=0; aux<listaTurnee.get_lista()[i].get_nrrunde();aux++)
                        std::cout<< "R"<<aux+1<<" ";
                    std::cout<<"\n";
                    std::cout<<"Introdu numarul rundei: ";
                    int nrrunda;
                    std::cin>>nrrunda;
                    if(nrrunda<1 || nrrunda>listaTurnee.get_lista()[i].get_nrrunde())
                    {std::cout<<"Nu exista runda cu numarul "<<nrrunda<<"\n\n\n";
                        MeniuTurneu(utilizator, listaTurnee, i);}
                    else{
                        MeniuRunda(utilizator,listaTurnee,i,nrrunda-1);
                    }
                    break;
                }

                case 2: {
                    MeniuListaStart(utilizator,listaTurnee,i);
                    break;
                }

                default: {
                    std::cout << "Nu exista optiunea!";
                    MeniuTurneu(utilizator, listaTurnee, i);
                }

            }


            // Alte opțiuni specifice pentru administrator
        } else if (dynamic_cast<Guest *>(utilizator)) {
            std::cout << "1)Selecteaza runda: ";
            for(int aux=0; aux<listaTurnee.get_lista()[i].get_nrrunde();aux++)
                std::cout<< "R"<<aux+1<<" ";
            std::cout<<"\n";

            std::cout << "Selecteaza optiunea: ";

            int optiune;
            std::cin >> optiune;
            switch (optiune) {
                case 0: {
                    aMeniu(utilizator, listaTurnee);
                    break;
                }
                case 1:{std::cout<<"Rundele sunt: ";
                    for(int aux=0; aux<listaTurnee.get_lista()[i].get_nrrunde();aux++)
                        std::cout<< "R"<<aux+1<<" ";
                    std::cout<<"\n";
                    std::cout<<"Introdu numarul rundei: ";
                    int nrrunda;
                    std::cin>>nrrunda;
                    if(nrrunda<1 || nrrunda>listaTurnee.get_lista()[i].get_nrrunde())
                    {std::cout<<"Nu exista runda cu numarul "<<nrrunda<<"\n\n\n";
                        MeniuTurneu(utilizator, listaTurnee, i);}
                    else{
                        MeniuRunda(utilizator,listaTurnee,i,nrrunda-1);
                    }
                    break;
                }
                default: {
                    MeniuTurneu(utilizator, listaTurnee, i);
                    break;
                }

            }


        }


    }
}

void Meniu::MeniuCereri(Utilizator *utilizator, ListaTurnee &listaTurnee,unsigned int i) {
    if (dynamic_cast<Administrator *>(utilizator)) {
        std::cout << "0)Inapoi\n";
        std::cout << "1)Accepta cerere\n";
        std::cout << "2)Refuza cerere\n";
        listaTurnee.get_lista()[i].afiseaza_lista_cereri();

        std::cout << "\n\nSelecteaza optiunea: ";
        std::cout << "\n\n";
        int optiune;
        std::cin >> optiune;
        switch (optiune) {
            case 0: {
                MeniuTurneu(utilizator, listaTurnee, i);
                break;
            }
            case 1: {
                listaTurnee.get_lista()[i].accepta_cerere();
                MeniuCereri(utilizator, listaTurnee, i);
                break;
            }
            case 2: {
                listaTurnee.get_lista()[i].refuza_cerere();
                MeniuCereri(utilizator, listaTurnee, i);
                break;
            }
            default: {
                MeniuCereri(utilizator, listaTurnee, i);
                break;
            }
        }
    } else {
        std::cout << "Acces interzis!";
        MeniuTurneu(utilizator, listaTurnee, i);
    }
}


void Meniu::MeniuRunda(Utilizator* utilizator,ListaTurnee& listaTurnee,unsigned int i,int j) {
    std::cout << "0)Inapoi\n";
    if (dynamic_cast<Administrator *>(utilizator)) {
        // Afișează opțiunile specifice pentru administrator
        std::cout << "1)Introdu rezultatele\n\n";

        std::cout<<"Runda "<<j+1<<":\n\n";
        listaTurnee.get_lista()[i].get_listarunde()[j].afiseaza_runda();

        std::cout << "\n\nSelecteaza optiunea: ";
        int optiune;
        std::cin >> optiune;
        switch (optiune) {
            case 0: {
                MeniuTurneu(utilizator, listaTurnee,i);
                break;
            }
            case 1: {
                std::cout<<"Alegeti dintre: 1, 0, -1:\n1 -> 1-0\n0 -> 1/2-1/2\n-1 -> 0-1\nIntroduceti rezultatele:\n";
                for(auto & aux : listaTurnee.get_lista()[i].get_listarunde()[j].get_partide())
                    if(aux.get_negru().get_nume()!="Bye" && aux.get_negru().get_prenume()!=" ")
                    {std::cout<<aux.get_alb().get_nume()<<" ";
                        std::cout<<aux.get_alb().get_prenume()<<" ";
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
                        std::cout<<" ";
                        std::cout<<aux.get_negru().get_nume()<<" ";
                        std::cout<<aux.get_negru().get_prenume()<<" Rezultat:";
                        int rez;
                        std::cin>>rez;

                        aux.set_rezultat(rez);
                        std::cout<<"\n";
                        listaTurnee.get_lista()[i].ordoneaza_dupa_puncte();
                    }
                MeniuRunda(utilizator,listaTurnee,i,j);
                break;
            }

            default: {
                std::cout << "Nu exista optiunea!";
                MeniuRunda(utilizator,listaTurnee,i,j);
            }

        }


        // Alte opțiuni specifice pentru administrator
    } else if (dynamic_cast<Guest *>(utilizator)) {
        std::cout << "0)Inapoi\n\n";

        //void afiseaza runda
        std::cout<<"\n\nIntrodu 0 pentru a iesi: ";
        int optiune;
        std::cin >> optiune;
        if(optiune==0)
        {MeniuTurneu(utilizator, listaTurnee, i);}
        else
        {MeniuRunda(utilizator, listaTurnee, i,j);}

    }
}

void Meniu::MeniuListaStart(Utilizator *utilizator, ListaTurnee &listaTurnee, unsigned int i){
    std::cout<<"Aceasta este lista de start:\n";
    listaTurnee.get_lista()[i].afiseaza_lista_jucatori();
    std::cout<<"\n\nIntroduceti 0 pentru a iesi din lista de start: ";
    int optiune;
    std::cin>>optiune;
    if(optiune==0)
        MeniuTurneu(utilizator, listaTurnee, i);
    else{std::cout<<"Tasta gresita! Incercati din nou!";
        MeniuListaStart(utilizator,listaTurnee,i);}


}