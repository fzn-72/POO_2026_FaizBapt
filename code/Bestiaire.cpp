#include "Bestiaire.h"
#include "Console.h"
#include <iostream>

void Bestiaire::ajouterEntree(const std::string& nom) {
    entrees.push_back(nom);
}

void Bestiaire::afficher() const {
    Console::titre("Bestiaire");
    for (std::size_t i = 0; i < entrees.size(); ++i) {
        std::cout << Console::cyan << entrees[i] << Console::reset << std::endl;
    }
}
