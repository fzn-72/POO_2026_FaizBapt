#ifndef CATALOGUEACT_H
#define CATALOGUEACT_H

#include "ActionACT.h"
#include <map>
#include <string>

class CatalogueACT {
private:
    std::map<std::string, ActionACT> actions;

public:
    CatalogueACT();
    ActionACT getAction(const std::string& id) const;
};

#endif
