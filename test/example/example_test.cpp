//
// Created by Xtreme Pc on 4/21/2024.
//
#include <gtest/gtest.h>
#include "ListaTurnee.h"

TEST(ListaTurneeTest, InitializareListaGoala) {
    ListaTurnee listaTurnee;
    EXPECT_EQ(listaTurnee.get_nr_turnee(), 0);
}

//TEST(ListaTurneeTest, AdaugareSiEliminareTurneu) {
//    ListaTurnee listaTurnee;
//    Turneu turneu("NumeTurneu");
//    listaTurnee.adaugare_turneu();
//    EXPECT_EQ(listaTurnee.get_nr_turnee(), 1);
//
//    listaTurnee.eliminare_turneu();
//    EXPECT_EQ(listaTurnee.get_nr_turnee(), 0);
//}



//TEST(ListaTurneeTest, CitesteSiAfiseazaNTurnee) {
//    ListaTurnee listaTurnee;
//
//    // Simulăm input-ul utilizatorului
//    std::istringstream input("3\n");
//    std::cin.rdbuf(input.rdbuf());
//
//    // Capturăm output-ul pentru a-l verifica mai târziu
//    testing::internal::CaptureStdout();
//
//    // Apelăm funcția
//    listaTurnee.citeste_si_afiseaza_n_turnee();
//
//    // Verificăm că lista de turnee nu este goală
//    EXPECT_GT(listaTurnee.get_nr_turnee(), 0);
//
//    // Verificăm că numărul de turnee adăugate este cel corect
//    EXPECT_EQ(listaTurnee.get_nr_turnee(), 3);
//
//    // Verificăm că nu se afișează nimic
//    std::string output = testing::internal::GetCapturedStdout();
//    EXPECT_TRUE(output.empty());
//}

#include "Partida.h"
#include "Jucator.h"

TEST(PartidaTest, TestGetterAndSetter) {
    Jucator alb("John", "Doe", 1500);
    Jucator negru("Jane", "Smith", 1600);
    Partida partida;

    // Setăm jucătorii și rezultatul partidei
    partida.set_alb(alb);
    partida.set_negru(negru);
    partida.set_rezultat(1); // Exemplu de rezultat, de exemplu 1 pentru victorie alb

    // Verificăm că jucătorii sunt setați corect
    EXPECT_EQ(partida.get_alb().get_nume(), "John");
    EXPECT_EQ(partida.get_negru().get_nume(), "Jane");

    // Verificăm că rezultatul este setat corect
    EXPECT_EQ(partida.getRezultat(), 1);
}

TEST(JucatorTest, TestConstructorAndGetters) {
    Jucator jucator("John", "Doe", 1500, 3.5);

    // Verificăm că constructorul și getterii funcționează corect
    EXPECT_EQ(jucator.get_nume(), "John");
    EXPECT_EQ(jucator.get_prenume(), "Doe");
    EXPECT_EQ(jucator.get_rating(), 1500);
    EXPECT_EQ(jucator.get_puncte(), 3.5);
}

TEST(JucatorTest, TestOperatorAssignment) {
    Jucator jucator1("John", "Doe", 1500, 3.5);
    Jucator jucator2;

    // Folosim operatorul de atribuire
    jucator2 = jucator1;

    // Verificăm că jucator2 a preluat corect valorile jucatorului 1
    EXPECT_EQ(jucator2.get_nume(), "John");
    EXPECT_EQ(jucator2.get_prenume(), "Doe");
    EXPECT_EQ(jucator2.get_rating(), 1500);
    EXPECT_EQ(jucator2.get_puncte(), 3.5);
}