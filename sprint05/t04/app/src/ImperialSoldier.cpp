#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier() : Soldier("Martin", 100) {
    std::cout << "Imperial soldier was created" << std::endl;
}

ImperialSoldier::~ImperialSoldier() {
    std::cout << "Imperial soldier was deleted" << std::endl;
    // delete this;
}