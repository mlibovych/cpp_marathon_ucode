#include "Dragonborn.h"

void Dragonborn::executeAction(const Actions action) {
    std::map<Actions, void (Dragonborn::*)(void) const> actions {
        {Dragonborn::Actions::Shout, &Dragonborn::shoutThuum},
        {Dragonborn::Actions::Magic, &Dragonborn::attackWithMagic},
        {Dragonborn::Actions::Weapon, &Dragonborn::attackWithWeapon}
    };
    std::invoke(actions[action], this);
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul" << std::endl;
}
void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*" << std::endl;

}
void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*" << std::endl;
}