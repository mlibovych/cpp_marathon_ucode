#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier() : Soldier("Flynn", 100) {
    std::cout << "Stormcloak soldier was created" << std::endl;
}

StormcloakSoldier::~StormcloakSoldier() {
    std::cout << "Stormcloak soldier was deleted" << std::endl;
    // delete this;
}
