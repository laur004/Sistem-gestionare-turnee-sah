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

TEST(ListaTurneeTest, CautareTurneuDupaNume) {
    ListaTurnee listaTurnee;
    Turneu turneu("NumeTurneu");
    listaTurnee.adaugare_turneu();

    testing::internal::CaptureStdout();
    listaTurnee.cautare_turneu_nume();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("NumeTurneu"), std::string::npos);
}

TEST(ListaTurneeTest, CitesteSiAfiseazaNTurnee) {
    ListaTurnee listaTurnee;
    testing::internal::CaptureStdout();
    listaTurnee.citeste_si_afiseaza_n_turnee();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty()); // Verificăm dacă ieșirea nu este goală
}
