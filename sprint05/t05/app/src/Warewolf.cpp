#include "Warewolf.h"

Creature::Creature() {
    std::cout << "Creature was created" << std::endl;
}

Creature::~Creature() {
    std::cout << "Creature was deleted" << std::endl;
}

Warewolf::Warewolf() : Creature() {
    std::cout << "Werewolf was created" << std::endl;
}

Warewolf::~Warewolf()  {
    std::cout << "Werewolf was deleted" << std::endl;
}