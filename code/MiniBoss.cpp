#include "MiniBoss.h"

MiniBoss::MiniBoss(const std::string& nom,
                   int hp,
                   int attaque,
                   int defense,
                   int objectifMercy,
                   const std::vector<std::string>& idsActions)
    : Monstre(nom, Categorie::MINIBOSS, hp, attaque, defense, objectifMercy, idsActions) {}

int MiniBoss::getNbActionsACT() const {
    return 3;
}

