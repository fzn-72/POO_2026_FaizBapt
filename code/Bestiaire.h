#ifndef BESTIAIRE_H
#define BESTIAIRE_H

#include <string>
#include <vector>

class Bestiaire {
private:
    std::vector<std::string> entrees;

public:
    void ajouterEntree(const std::string& nom);
    void afficher() const;
};

#endif
