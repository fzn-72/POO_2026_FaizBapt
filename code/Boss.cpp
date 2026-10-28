#include "Boss.h"

Boss::Boss(const std::string& nom,
           int hp,
           int attaque,
           int defense,
           int objectifMercy,
           const std::vector<std::string>& idsActions)
    : Monstre(nom, Categorie::BOSS, hp, attaque, defense, objectifMercy, idsActions) {}

int Boss::getNbActionsACT() const {
    return 4;
}

