#ifndef ENTITE_H
#define ENTITE_H

class Entite {
protected:
    int hp;
    int hpMax;
    int attaque;
    int defense;

public:
    Entite(int hp = 0, int hpMax = 0, int attaque = 0, int defense = 0);
    virtual ~Entite();

    bool estVivant() const;
    int attaquer(Entite& cible);
    int getHp() const;
    int getHpMax() const;
};

#endif
