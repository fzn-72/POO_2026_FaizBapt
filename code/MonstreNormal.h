#ifndef MONSTRENORMAL_H
#define MONSTRENORMAL_H

#include "Monstre.h"

class MonstreNormal : public Monstre {
public:
    MonstreNormal(const std::string& nom,
                  int hp,
                  int attaque,
                  int defense,
                  int objectifMercy,
                  const std::vector<std::string>& idsActions);
    int getNbActionsACT() const override;
};

#endif
