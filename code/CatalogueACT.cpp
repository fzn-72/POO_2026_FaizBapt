#include "CatalogueACT.h"

CatalogueACT::CatalogueACT() {
    actions["COMPLIMENT"] = ActionACT("COMPLIMENT", "Vous dites : \"Ton style est vraiment impressionnant.\"", 50);
    actions["DISCUSS"] = ActionACT("DISCUSS", "Vous demandez calmement pourquoi il veut se battre.", 50);
    actions["JOKE"] = ActionACT("JOKE", "Vous lancez : \"Pourquoi les monstres n'aiment pas les maths ? Trop de problemes.\"", 40);
    actions["PET"] = ActionACT("PET", "Vous faites un geste rassurant pour montrer que vous n'etes pas une menace.", 45);
    actions["OBSERVE"] = ActionACT("OBSERVE", "Vous observez ses mouvements et trouvez comment le calmer.", 35);
    actions["OFFER_SNACK"] = ActionACT("OFFER_SNACK", "Vous proposez un snack. Le monstre hesite, puis se detend.", 50);
    actions["DANCE"] = ActionACT("DANCE", "Vous improvisez quelques pas ridicules. L'ambiance devient moins tendue.", 45);
    actions["REASON"] = ActionACT("REASON", "Vous expliquez qu'aucun de vous deux n'a besoin d'etre blesse.", 50);
    actions["INSULT"] = ActionACT("INSULT", "Vous dites quelque chose de blessant. Le monstre se braque.", -30);
    actions["PLAY_LYRE"] = ActionACT("PLAY_LYRE", "Vous jouez quelques notes de lyre. Le monstre baisse sa garde.", 55);
    actions["PRAY"] = ActionACT("PRAY", "Vous adressez une courte priere aux dieux pour apaiser le combat.", 45);
    actions["OFFER_AMBROSIA"] = ActionACT("OFFER_AMBROSIA", "Vous offrez une goutte d'ambroisie. Le geste est respecte.", 55);
    actions["BOW"] = ActionACT("BOW", "Vous inclinez la tete avec respect, sans chercher la provocation.", 40);
    actions["RIDDLE"] = ActionACT("RIDDLE", "Vous proposez une enigme. Le monstre reflechit au lieu d'attaquer.", 50);
    actions["CALL_HEROES"] = ActionACT("CALL_HEROES", "Vous evoquez le courage des anciens heros grecs.", 45);
}

ActionACT CatalogueACT::getAction(const std::string& id) const {
    std::map<std::string, ActionACT>::const_iterator it = actions.find(id);
    if (it != actions.end()) {
        return it->second;
    }
    return ActionACT();
}
