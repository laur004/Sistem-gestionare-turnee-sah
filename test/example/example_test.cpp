//
// Created by Xtreme Pc on 4/21/2024.
//
#include <gtest/gtest.h>
#include "ListaTurnee.h"

TEST(ListaTurneeTest, InitializareListaGoala) {
    ListaTurnee listaTurnee;
    EXPECT_EQ(listaTurnee.get_nr_turnee(), 0);
}

TEST(ListaTurneeTest, AdaugareSiEliminareTurneu) {
    ListaTurnee listaTurnee;
    Turneu turneu("NumeTurneu");
    listaTurnee.adaugare_turneu();
    EXPECT_EQ(listaTurnee.get_nr_turnee(), 1);

    listaTurnee.eliminare_turneu();
    EXPECT_EQ(listaTurnee.get_nr_turnee(), 0);
}



TEST(ListaTurneeTest, CitesteSiAfiseazaNTurnee) {
    ListaTurnee listaTurnee;

    // Simulăm input-ul utilizatorului
    std::istringstream input("3\n");
    std::cin.rdbuf(input.rdbuf());

    // Capturăm output-ul pentru a-l verifica mai târziu
    testing::internal::CaptureStdout();

    // Apelăm funcția
    listaTurnee.citeste_si_afiseaza_n_turnee();

    // Verificăm că lista de turnee nu este goală
    EXPECT_GT(listaTurnee.get_nr_turnee(), 0);

    // Verificăm că numărul de turnee adăugate este cel corect
    EXPECT_EQ(listaTurnee.get_nr_turnee(), 3);

    // Verificăm că nu se afișează nimic
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}
