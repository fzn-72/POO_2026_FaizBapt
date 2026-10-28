#include "Console.h"
#include "Jeu.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    Console::activerCouleurs();
    Jeu jeu;

    jeu.creerJoueur();
    jeu.chargerItems();
    jeu.chargerMonstres();
    jeu.menuPrincipal();

    return 0;
}
