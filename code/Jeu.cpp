#include "Jeu.h"
#include "Boss.h"
#include "Console.h"
#include "MiniBoss.h"
#include "MonstreNormal.h"
#include "Objet.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

static std::vector<std::string> couper(const std::string& ligne) {
    std::vector<std::string> champs;
    std::string champ;
    std::stringstream ss(ligne);
    while (std::getline(ss, champ, ';')) {
        champs.push_back(champ);
    }
    return champs;
}

static std::string attaqueMythologique(const Monstre& monstre) {
    int choix = std::rand() % 3;
    std::string nom = monstre.getNom();

    if (nom == "Satyre") {
        if (choix == 0) return "Le Satyre vous assomme avec un air de flute beaucoup trop aigu.";
        if (choix == 1) return "Le Satyre vous charge en riant comme dans une fete de Dionysos.";
        return "Le Satyre lance une grappe de raisin sacree avec une precision vexante.";
    }
    if (nom == "Nymphe") {
        if (choix == 0) return "La Nymphe invoque une vague claire qui vous repousse.";
        if (choix == 1) return "La Nymphe fait jaillir des racines autour de vos pieds.";
        return "La Nymphe appelle le vent des sources contre vous.";
    }
    if (nom == "Minotaure") {
        if (choix == 0) return "Le Minotaure frappe comme s'il voulait ouvrir un mur du labyrinthe.";
        if (choix == 1) return "Le Minotaure charge, cornes en avant.";
        return "Le Minotaure fait trembler le sol d'un coup de sabot.";
    }
    if (nom == "Meduse") {
        if (choix == 0) return "Meduse tente de vous petrifier d'un regard glacial.";
        if (choix == 1) return "Les serpents de Meduse sifflent et attaquent en meme temps.";
        return "Meduse projette un eclat de pierre maudite.";
    }
    if (choix == 0) return "Cerbere mord avec l'une de ses trois tetes.";
    if (choix == 1) return "Cerbere fait tomber une foudre de Zeus autour de l'arene.";
    return "Cerbere pousse un hurlement venu des portes des Enfers.";
}

Jeu::Jeu() : joueur("Joueur") {}

Jeu::~Jeu() {
    for (std::size_t i = 0; i < monstres.size(); ++i) {
        delete monstres[i];
    }
}

void Jeu::creerJoueur() {
    std::string nom;
    Console::effacer();
    Console::titre("ALTERDUNE");
    std::cout << Console::blancFort << "Nom du joueur : " << Console::reset;
    std::getline(std::cin, nom);
    if (nom.empty()) {
        nom = "Joueur";
    }
    joueur = Joueur(nom);
    std::cout << Console::vert << "Personnage cree : " << nom << Console::reset << std::endl;
}

void Jeu::chargerItems() {
    std::ifstream fichier("items.csv");
    std::string ligne;

    while (std::getline(fichier, ligne)) {
        std::vector<std::string> c = couper(ligne);
        if (c.size() == 4) {
            joueur.getInventaire().ajouterObjet(Objet(c[0], c[1], std::atoi(c[2].c_str()), std::atoi(c[3].c_str())));
        }
    }
}

void Jeu::chargerMonstres() {
    std::ifstream fichier("monsters.csv");
    std::string ligne;

    while (std::getline(fichier, ligne)) {
        std::vector<std::string> c = couper(ligne);
        if (c.size() < 8) {
            continue;
        }

        std::vector<std::string> actions;
        for (std::size_t i = 6; i < c.size(); ++i) {
            if (c[i] != "-") {
                actions.push_back(c[i]);
            }
        }

        int hp = std::atoi(c[2].c_str());
        int attaque = std::atoi(c[3].c_str());
        int defense = std::atoi(c[4].c_str());
        int objectifMercy = std::atoi(c[5].c_str());

        if (c[0] == "NORMAL") {
            monstres.push_back(new MonstreNormal(c[1], hp, attaque, defense, objectifMercy, actions));
        } else if (c[0] == "MINIBOSS") {
            monstres.push_back(new MiniBoss(c[1], hp, attaque, defense, objectifMercy, actions));
        } else if (c[0] == "BOSS") {
            monstres.push_back(new Boss(c[1], hp, attaque, defense, objectifMercy, actions));
        }
    }
}

void Jeu::menuPrincipal() {
    int choix = -1;
    while (choix != 0) {
        Console::effacer();
        Console::titre("Menu principal");
        std::cout << Console::jaune << "1." << Console::reset << " Combat" << std::endl;
        std::cout << Console::jaune << "2." << Console::reset << " Statistiques" << std::endl;
        std::cout << Console::jaune << "3." << Console::reset << " Inventaire" << std::endl;
        std::cout << Console::jaune << "4." << Console::reset << " Bestiaire" << std::endl;
        std::cout << Console::gris << "0." << Console::reset << " Quitter" << std::endl;
        std::cout << Console::blancFort << "Choix : " << Console::reset;
        std::cin >> choix;

        if (choix == 1) {
            lancerCombat();
        } else if (choix == 2) {
            Console::effacer();
            joueur.afficherStatistiques();
            std::cout << Console::gris << "\nEntrez un nombre pour revenir au menu : " << Console::reset;
            int pause = 0;
            std::cin >> pause;
        } else if (choix == 3) {
            Console::effacer();
            joueur.getInventaire().afficher();
            std::cout << Console::gris << "\nEntrez un nombre pour revenir au menu : " << Console::reset;
            int pause = 0;
            std::cin >> pause;
        } else if (choix == 4) {
            Console::effacer();
            bestiaire.afficher();
            std::cout << Console::gris << "\nEntrez un nombre pour revenir au menu : " << Console::reset;
            int pause = 0;
            std::cin >> pause;
        }
    }
}

void Jeu::lancerCombat() {
    if (monstres.empty()) {
        std::cout << Console::jaune << "Aucun monstre charge." << Console::reset << std::endl;
        return;
    }

    Monstre* monstre = monstres[0];
    bool combatTermine = false;
    bool retirerMonstre = false;
    std::string dernierMessage = "Mercy : utilisez ACT pour remplir la barre, puis choisissez Epargner.";

    while (!combatTermine && joueur.estVivant() && monstre->estVivant()) {
        bool actionConsommee = false;

        Console::effacer();
        Console::titre("Combat contre " + monstre->getNom());
        std::cout << Console::jaune << "Categorie : " << monstre->getCategorieTexte() << Console::reset << std::endl;
        std::cout << Console::cyan << dernierMessage << Console::reset << std::endl;
        Console::separation();
        std::cout << Console::rouge << monstre->getNom() << Console::reset
                  << " [" << monstre->getCategorieTexte() << "] PV : "
                  << monstre->getHp() << "/" << monstre->getHpMax()
                  << " | " << Console::cyan << "Mercy : " << monstre->getMercy()
                  << "/" << monstre->getObjectifMercy() << Console::reset << std::endl;
        if (monstre->getMercy() >= monstre->getObjectifMercy()) {
            std::cout << Console::vert << "Mercy complete : vous pouvez choisir Epargner." << Console::reset << std::endl;
        }
        std::cout << Console::vert << "Joueur" << Console::reset << " PV : "
                  << joueur.getHp() << "/" << joueur.getHpMax() << std::endl;
        std::cout << Console::jaune << "1." << Console::reset << " Attaquer" << std::endl;
        std::cout << Console::jaune << "2." << Console::reset << " ACT" << std::endl;
        std::cout << Console::jaune << "3." << Console::reset << " Utiliser un objet" << std::endl;
        std::cout << Console::jaune << "4." << Console::reset << " Epargner" << std::endl;
        std::cout << Console::blancFort << "Choix : " << Console::reset;

        int choix = 0;
        std::cin >> choix;

        if (choix == 1) {
            int degats = joueur.attaquer(*monstre);
            dernierMessage = "Vous attaquez " + monstre->getNom() + " et infligez " + std::to_string(degats) + " degats.";
            actionConsommee = true;
        } else if (choix == 2) {
            Console::effacer();
            Console::titre("ACT");
            const std::vector<std::string>& actions = monstre->getIdsActions();
            for (std::size_t i = 0; i < actions.size(); ++i) {
                ActionACT action = catalogue.getAction(actions[i]);
                std::cout << Console::jaune << i + 1 << "." << Console::reset << " "
                          << action.getId() << " - " << action.getTexte()
                          << " (" << Console::cyan << "Mercy "
                          << (action.getEffetMercy() >= 0 ? "+" : "")
                          << action.getEffetMercy() << Console::reset << ")" << std::endl;
            }
            std::cout << Console::gris << "0." << Console::reset << " Retour" << std::endl;

            int choixAction = 0;
            std::cout << Console::blancFort << "Action : " << Console::reset;
            std::cin >> choixAction;
            if (choixAction == 0) {
                dernierMessage = "Retour au choix principal.";
            } else if (choixAction >= 1 && choixAction <= static_cast<int>(actions.size())) {
                ActionACT action = catalogue.getAction(actions[choixAction - 1]);
                action.executer(*monstre);
                dernierMessage = action.getTexte();
                actionConsommee = true;
            } else {
                dernierMessage = "Action invalide.";
            }
        } else if (choix == 3) {
            Console::effacer();
            joueur.getInventaire().afficher();
            std::cout << Console::gris << "0." << Console::reset << " Retour" << std::endl;
            int choixObjet = 0;
            std::cout << Console::blancFort << "Objet : " << Console::reset;
            std::cin >> choixObjet;
            if (choixObjet == 0) {
                dernierMessage = "Retour au choix principal.";
            } else if (joueur.getInventaire().utiliserObjet(choixObjet, joueur)) {
                dernierMessage = "Objet utilise.";
                actionConsommee = true;
            } else {
                dernierMessage = "Objet invalide ou indisponible.";
            }
        } else if (choix == 4) {
            if (monstre->getMercy() >= monstre->getObjectifMercy()) {
                dernierMessage = "Vous epargnez " + monstre->getNom() + ".";
                joueur.ajouterEpargne();
                joueur.ajouterVictoire();
                bestiaire.ajouterEntree(monstre->getNom());
                combatTermine = true;
                retirerMonstre = true;
                actionConsommee = true;
            } else {
                int manque = monstre->getObjectifMercy() - monstre->getMercy();
                dernierMessage = monstre->getNom() + " ne veut pas encore partir. Il manque " + std::to_string(manque) + " Mercy.";
                actionConsommee = true;
            }
        } else {
            dernierMessage = "Choix invalide.";
        }

        if (actionConsommee && !combatTermine && monstre->estVivant()) {
            int degats = monstre->attaquer(joueur);
            dernierMessage += " " + attaqueMythologique(*monstre) + " (" + std::to_string(degats) + " degats)";
        }

        if (!monstre->estVivant()) {
            dernierMessage = monstre->getNom() + " est vaincu.";
            joueur.ajouterTue();
            joueur.ajouterVictoire();
            bestiaire.ajouterEntree(monstre->getNom());
            combatTermine = true;
            retirerMonstre = true;
        }
    }

    Console::effacer();
    Console::titre("Fin du combat");
    std::cout << Console::cyan << dernierMessage << Console::reset << std::endl;
    std::cout << Console::gris << "\nEntrez un nombre pour revenir au menu : " << Console::reset;
    int pause = 0;
    std::cin >> pause;

    if (retirerMonstre) {
        delete monstres[0];
        monstres.erase(monstres.begin());
    }

    if (!joueur.estVivant()) {
        verifierFinPartie();
    }
}

void Jeu::verifierFinPartie() {
    if (!joueur.estVivant()) {
        std::cout << Console::rouge << "Fin de partie." << Console::reset << std::endl;
    }
}
