#include <iostream>

#include "Axe.h"
#include "Sword.h"
#include "ImperialSoldier.h"
#include "StormcloakSoldier.h"


int main(int argc, char** argv) {
    try {
        ImperialSoldier* imp = new ImperialSoldier();
        StormcloakSoldier* storm = new StormcloakSoldier();

        if (argc != 3) {
            throw std::runtime_error("usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]");
        }
        int sword_d = std::stoi(argv[1]);
        int axe_d = std::stoi(argv[2]);
        if (sword_d < 10 || sword_d > 20 || axe_d < 10 || axe_d > 20) {
            throw std::invalid_argument("error");
        }
        imp->setWeapon(new Sword(sword_d));
        storm->setWeapon(new Axe(axe_d));
        while (1) {
            imp->attack(*storm);
            if (storm->getHealth() <= 0) {
                std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
                std::cout << "Imperial has won!" << std::endl;
                break;
            }
            storm->attack(*imp);
            if (imp->getHealth() <= 0) {
                std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
                std::cout << "Stormcloak has won!" << std::endl;
                break;
            }
            std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
        }
    }
    catch (std::runtime_error& re) {
        std::cerr << re.what() << std::endl;
    }
    catch (std::invalid_argument& ex) {
        std::cerr << "Damage has to be in a range of 10-20 points" << std::endl;
    }
}