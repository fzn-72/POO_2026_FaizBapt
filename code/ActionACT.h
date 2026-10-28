#ifndef ACTIONACT_H
#define ACTIONACT_H

#include <string>

class Monstre;

class ActionACT {
private:
    std::string id;
    std::string texte;
    int effetMercy;

public:
    ActionACT(const std::string& id = "", const std::string& texte = "", int effetMercy = 0);

    void executer(Monstre& monstre) const;
    std::string getId() const;
    std::string getTexte() const;
    int getEffetMercy() const;
};

#endif
