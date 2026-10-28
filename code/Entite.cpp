#include "Entite.h"
#include <cstdlib>

Entite::Entite(int hp, int hpMax, int attaque, int defense)
    : hp(hp), hpMax(hpMax), attaque(attaque), defense(defense) {}

Entite::~Entite() {}

bool Entite::estVivant() const {
    return hp > 0;
}

int Entite::attaquer(Entite& cible) {
    int degats = attaque - cible.defense;
    degats += (std::rand() % 7) - 3;

    int chance = std::rand() % 100;
    if (chance < 10) {
        degats = degats / 2;
    } else if (chance >= 90) {
        degats += 4;
    }

    if (degats < 1) {
        degats = 1;
    }

    cible.hp -= degats;
    if (cible.hp < 0) {
        cible.hp = 0;
    }

    return degats;
}

int Entite::getHp() const {
    return hp;
}

int Entite::getHpMax() const {
    return hpMax;
}
