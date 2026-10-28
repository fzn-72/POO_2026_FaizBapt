#include "MonstreNormal.h"

MonstreNormal::MonstreNormal(const std::string& nom,
                             int hp,
                             int attaque,
                             int defense,
                             int objectifMercy,
                             const std::vector<std::string>& idsActions)
    : Monstre(nom, Categorie::NORMAL, hp, attaque, defense, objectifMercy, idsActions) {}

int MonstreNormal::getNbActionsACT() const {
    return 2;
}

