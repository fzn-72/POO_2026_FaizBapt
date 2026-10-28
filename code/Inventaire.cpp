#include "Inventaire.h"
#include "Console.h"
#include <iostream>

void Inventaire::ajouterObjet(const Objet& obj) {
    objets.push_back(obj);
}

bool Inventaire::utiliserObjet(const std::string& nom, Joueur& joueur) {
    for (std::size_t i = 0; i < objets.size(); ++i) {
        if (objets[i].getNom() == nom) {
            return objets[i].utiliser(joueur);
        }
    }
    return false;
}

bool Inventaire::utiliserObjet(int index, Joueur& joueur) {
    if (index < 1 || index > static_cast<int>(objets.size())) {
        return false;
    }
    return objets[index - 1].utiliser(joueur);
}

void Inventaire::afficher() const {
    Console::titre("Inventaire");
    for (std::size_t i = 0; i < objets.size(); ++i) {
        std::cout << Console::jaune << i + 1 << "." << Console::reset << " "
                  << objets[i].getNom() << " x" << objets[i].getQuantite()
                  << " - " << objets[i].getDescription() << std::endl;
    }
}
