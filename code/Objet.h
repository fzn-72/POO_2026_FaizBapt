#ifndef OBJET_H
#define OBJET_H

#include <string>

class Joueur;

class Objet {
private:
    std::string nom;
    std::string type;
    int valeur;
    int quantite;

public:
    Objet(const std::string& nom = "", const std::string& type = "", int valeur = 0, int quantite = 0);

    bool utiliser(Joueur& cible);
    std::string getNom() const;
    std::string getType() const;
    int getValeur() const;
    int getQuantite() const;
    std::string getDescription() const;
};

#endif
