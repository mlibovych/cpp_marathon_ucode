#include "Soldier.h"

Soldier::Soldier(std::string&& name, int health) : m_name(name), m_health(health) {
    std::cout << "Soldier " << m_name << " was created" << std::endl;
}

Soldier::~Soldier() {
    std::cout << "Soldier " << m_name << " was deleted" << std::endl;
    delete m_weapon;
}

void Soldier::attack(Soldier& other) {
    std::cout <<  m_name << " attaks " << other.m_name << " and deals " << m_weapon->getDamage() << " damage" << std::endl;
    other.m_health -= m_weapon->getDamage();
}

void Soldier::setWeapon(Weapon* weapon) {
    m_weapon = weapon;
}

int Soldier::getHealth() const {
    return m_health;
}
