#include "Monstre.h"

Monstre::Monstre(const std::string& nom,
                 Categorie categorie,
                 int hp,
                 int attaque,
                 int defense,
                 int objectifMercy,
                 const std::vector<std::string>& idsActions)
    : Entite(hp, hp, attaque, defense),
      nom(nom),
      categorie(categorie),
      mercy(0),
      objectifMercy(objectifMercy),
      idsActions(idsActions) {}

Monstre::~Monstre() {}

void Monstre::modifierMercy(int valeur) {
    mercy += valeur;
    if (mercy < 0) {
        mercy = 0;
    }
    if (mercy > objectifMercy) {
        mercy = objectifMercy;
    }
}

std::string Monstre::getNom() const {
    return nom;
}

std::string Monstre::getCategorieTexte() const {
    if (categorie == Categorie::NORMAL) {
        return "Monstre normal";
    }
    if (categorie == Categorie::MINIBOSS) {
        return "MiniBoss";
    }
    return "Boss";
}

int Monstre::getMercy() const {
    return mercy;
}

int Monstre::getObjectifMercy() const {
    return objectifMercy;
}

const std::vector<std::string>& Monstre::getIdsActions() const {
    return idsActions;
}
