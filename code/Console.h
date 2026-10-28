#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace Console {
    const std::string reset = "\033[0m";
    const std::string rouge = "\033[31m";
    const std::string vert = "\033[32m";
    const std::string jaune = "\033[33m";
    const std::string bleu = "\033[34m";
    const std::string cyan = "\033[36m";
    const std::string blancFort = "\033[97m";
    const std::string gris = "\033[90m";

    void activerCouleurs();
    void effacer();
    void titre(const std::string& texte);
    void separation();
}

#endif
