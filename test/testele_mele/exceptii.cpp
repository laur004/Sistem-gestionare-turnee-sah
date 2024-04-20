#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "Meniu.h"
#include "../../cmake-build-debug/_deps/googletest-src/googlemock/include/gmock/gmock-matchers.h"

// Mock pentru ListaTurnee (dacă este necesar)
class MockListaTurnee : public ListaTurnee {
    // Implementează metodele necesare pentru teste
};

// Test pentru funcția Meniu::Login
TEST(MeniuTest, TestLogin) {
    std::istringstream input("a\n3\n2\n1\n0\n"); // Inputurile simulate: "a", "3", "2", "1", "0"
    std::ostringstream output;

    // Redirecționează std::cin și std::cout către fluxurile definite mai sus
    std::streambuf *orig_cin = std::cin.rdbuf(input.rdbuf());
    std::streambuf *orig_cout = std::cout.rdbuf(output.rdbuf());

    ListaTurnee listaTurnee; // Inițializează listaTurnee după nevoie

    // Rulează funcția Meniu::Login
    Meniu::Login(listaTurnee);

    // Verifică ieșirea produsă
    EXPECT_THAT(output.str(), testing::HasSubstr("Bine ai venit!"));
    EXPECT_THAT(output.str(), testing::HasSubstr("Trebuie sa alegi ca optiune numere nu litere!"));
    // Alte verificări pot fi adăugate aici în funcție de comportamentul așteptat

    // Restaurează fluxurile standard
    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);
}

int main(int argc, char **argv) {
    // Inițializează Google Test
    ::testing::InitGoogleTest(&argc, argv);
    // Rulează toate testele definite
    return RUN_ALL_TESTS();
}
