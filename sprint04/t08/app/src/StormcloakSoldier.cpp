#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier() {
    m_health = 100;
}

StormcloakSoldier::~StormcloakSoldier() {
    delete m_weapon;
    delete this;
}

void StormcloakSoldier::setWeapon(Axe* weapon) {
    m_weapon = weapon;
}

void StormcloakSoldier::attack(ImperialSoldier& enemy) {
    std::cout<< "Stormcloak soldier attacks and deals " << m_weapon->getDamage() << " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void StormcloakSoldier::consumeDamage(int amount) {
    m_health -= amount;
    std::cout<< "Stormcloak soldier consumes " << amount << " of damage";
    if (m_health <= 0) {
        std::cout << " and dies";
    }
    std::cout << std::endl;
}

int StormcloakSoldier::getHealth() const {
    return m_health;
}