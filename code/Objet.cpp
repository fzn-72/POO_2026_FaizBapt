#include "Objet.h"
#include "Joueur.h"

Objet::Objet(const std::string& nom, const std::string& type, int valeur, int quantite)
    : nom(nom), type(type), valeur(valeur), quantite(quantite) {}

bool Objet::utiliser(Joueur& cible) {
    if (quantite <= 0) {
        return false;
    }

    if (type == "HEAL") {
        cible.soigner(valeur);
    }
    quantite--;
    return true;
}

std::string Objet::getNom() const {
    return nom;
}

std::string Objet::getType() const {
    return type;
}

int Objet::getValeur() const {
    return valeur;
}

int Objet::getQuantite() const {
    return quantite;
}

std::string Objet::getDescription() const {
    if (type == "HEAL") {
        return "soigne " + std::to_string(valeur) + " PV";
    }
    return "effet inconnu";
}
