#pragma once

#include <iostream>

#include "Axe.h"
#include "ImperialSoldier.h"

class Axe;
class ImperialSoldier;

class StormcloakSoldier final {
public:
    StormcloakSoldier();
    ~StormcloakSoldier();

    void setWeapon(Axe* weapon);

    void attack(ImperialSoldier& enemy);

    void consumeDamage(int amount);

    int getHealth() const;
private:
    Axe* m_weapon;
    int m_health;
};