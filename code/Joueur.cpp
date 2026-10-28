#include "Joueur.h"
#include "Console.h"
#include <iostream>

Joueur::Joueur(const std::string& nom)
    : Entite(100, 100, 10, 2), nom(nom), nbTues(0), nbEpargnes(0), nbVictoires(0) {}

void Joueur::afficherStatistiques() const {
    Console::titre("Statistiques");
    std::cout << Console::blancFort << "Nom : " << Console::reset << nom << std::endl;
    std::cout << Console::vert << "PV : " << Console::reset << hp << "/" << hpMax << std::endl;
    std::cout << "Monstres tues : " << nbTues << std::endl;
    std::cout << "Monstres epargnes : " << nbEpargnes << std::endl;
    std::cout << "Victoires : " << nbVictoires << std::endl;
}

void Joueur::soigner(int valeur) {
    hp += valeur;
    if (hp > hpMax) {
        hp = hpMax;
    }
}

void Joueur::ajouterTue() {
    nbTues++;
}

void Joueur::ajouterEpargne() {
    nbEpargnes++;
}

void Joueur::ajouterVictoire() {
    nbVictoires++;
}

Inventaire& Joueur::getInventaire() {
    return inventaire;
}
