#ifndef MINIBOSS_H
#define MINIBOSS_H

#include "Monstre.h"

class MiniBoss : public Monstre {
public:
    MiniBoss(const std::string& nom,
             int hp,
             int attaque,
             int defense,
             int objectifMercy,
             const std::vector<std::string>& idsActions);
    int getNbActionsACT() const override;
};

#endif
