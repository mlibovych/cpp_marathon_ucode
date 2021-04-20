#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier() {
    m_health = 100;
}

ImperialSoldier::~ImperialSoldier() {
    delete m_weapon;
    delete this;
}

void ImperialSoldier::setWeapon(Sword* weapon) {
    m_weapon = weapon;
}

void ImperialSoldier::attack(StormcloakSoldier& enemy) {
    std::cout<< "Imperial soldier attacks and deals " << m_weapon->getDamage() << " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void ImperialSoldier::consumeDamage(int amount) {
    m_health -= amount;
    std::cout<< "Imperial soldier consumes " << amount << " of damage";
    if (m_health <= 0) {
        std::cout << " and dies";
    }
    std::cout << std::endl;
}

int ImperialSoldier::getHealth() const {
    return m_health;
}