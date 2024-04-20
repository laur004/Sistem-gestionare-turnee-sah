#include <gtest/gtest.h>
#include "ListaTurnee.h"
#include <sstream>
#include <iostream>

// Test pentru metoda citeste_si_afiseaza_n_turnee()
TEST(ListaTurneeTest, TestCitesteSiAfiseazaNTurnee) {
    // Simulăm input-ul pentru a citi 2 turnee
    std::istringstream input("2\nNumeTurneu1\nDetaliiTurneu1\nNumeTurneu2\nDetaliiTurneu2\n");

    // Salvăm std::cout original și redirecționăm ieșirea către un stringstream
    std::stringstream output;
    std::streambuf* original_cout = std::cout.rdbuf(output.rdbuf());

    // Redirecționăm std::cin către inputul simulat
    std::streambuf* original_cin = std::cin.rdbuf(input.rdbuf());

    // Inițializăm obiectul ListaTurnee și apelăm metoda
    ListaTurnee listaTurnee;
    listaTurnee.citeste_si_afiseaza_n_turnee();

    // Verificăm dacă ieșirea corespunde cu ce ne așteptăm
    std::string expected_output = "Numar turnee de adaugat sa adaugat: ";
    expected_output += "Introduceti datele pentru turneul 1:\n";
    expected_output += "Introduceti numele turneului: ";
    expected_output += "Introduceti detalii despre turneu: ";
    expected_output += "Turneu adaugat cu succes!\n";
    expected_output += "Introduceti datele pentru turneul 2:\n";
    expected_output += "Introduceti numele turneului: ";
    expected_output += "Introduceti detalii despre turneu: ";
    expected_output += "Turneu adaugat cu succes!\n";
    ASSERT_EQ(output.str(), expected_output);

    // Verificăm dacă lista de turnee conține cele două turnee adăugate
    ASSERT_EQ(listaTurnee.get_lista().size(), 2);
    ASSERT_EQ(listaTurnee.get_lista()[0].get_nume(), "NumeTurneu1");
    ASSERT_EQ(listaTurnee.get_lista()[1].get_nume(), "NumeTurneu2");

    // Restaurăm std::cout și std::cin
    std::cout.rdbuf(original_cout);
    std::cin.rdbuf(original_cin);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
