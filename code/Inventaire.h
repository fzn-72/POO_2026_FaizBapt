#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "Objet.h"
#include <string>
#include <vector>

class Joueur;

class Inventaire {
private:
    std::vector<Objet> objets;

public:
    void ajouterObjet(const Objet& obj);
    bool utiliserObjet(const std::string& nom, Joueur& joueur);
    bool utiliserObjet(int index, Joueur& joueur);
    void afficher() const;
};

#endif
