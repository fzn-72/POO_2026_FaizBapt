#ifndef BOSS_H
#define BOSS_H

#include "Monstre.h"

class Boss : public Monstre {
public:
    Boss(const std::string& nom,
         int hp,
         int attaque,
         int defense,
         int objectifMercy,
         const std::vector<std::string>& idsActions);
    int getNbActionsACT() const override;
};

#endif
