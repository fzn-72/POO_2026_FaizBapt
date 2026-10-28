#ifndef MONSTRE_H
#define MONSTRE_H

#include "Categorie.h"
#include "Entite.h"
#include <string>
#include <vector>

class Monstre : public Entite {
protected:
    std::string nom;
    Categorie categorie;
    int mercy;
    int objectifMercy;
    std::vector<std::string> idsActions;

public:
    Monstre(const std::string& nom,
            Categorie categorie,
            int hp,
            int attaque,
            int defense,
            int objectifMercy,
            const std::vector<std::string>& idsActions);
    virtual ~Monstre();

    void modifierMercy(int valeur);
    virtual int getNbActionsACT() const = 0;

    std::string getNom() const;
    std::string getCategorieTexte() const;
    int getMercy() const;
    int getObjectifMercy() const;
    const std::vector<std::string>& getIdsActions() const;
};

#endif
