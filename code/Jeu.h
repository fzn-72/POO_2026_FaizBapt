#ifndef JEU_H
#define JEU_H

#include "Bestiaire.h"
#include "CatalogueACT.h"
#include "Joueur.h"
#include "Monstre.h"
#include <vector>

class Jeu {
private:
    Joueur joueur;
    std::vector<Monstre*> monstres;
    CatalogueACT catalogue;
    Bestiaire bestiaire;

public:
    Jeu();
    ~Jeu();

    void creerJoueur();
    void chargerItems();
    void chargerMonstres();
    void menuPrincipal();
    void lancerCombat();
    void verifierFinPartie();
};

#endif
