#include "ActionACT.h"
#include "Monstre.h"

ActionACT::ActionACT(const std::string& id, const std::string& texte, int effetMercy)
    : id(id), texte(texte), effetMercy(effetMercy) {}

void ActionACT::executer(Monstre& monstre) const {
    monstre.modifierMercy(effetMercy);
}

std::string ActionACT::getId() const {
    return id;
}

std::string ActionACT::getTexte() const {
    return texte;
}

int ActionACT::getEffetMercy() const {
    return effetMercy;
}
