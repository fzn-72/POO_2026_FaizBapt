#ifndef JOUEUR_H
#define JOUEUR_H

#include "Entite.h"
#include "Inventaire.h"
#include <string>

class Joueur : public Entite {
private:
    std::string nom;
    int nbTues;
    int nbEpargnes;
    int nbVictoires;
    Inventaire inventaire;

public:
    Joueur(const std::string& nom = "Joueur");

    void afficherStatistiques() const;
    void soigner(int valeur);
    void ajouterTue();
    void ajouterEpargne();
    void ajouterVictoire();
    Inventaire& getInventaire();
};

#endif
