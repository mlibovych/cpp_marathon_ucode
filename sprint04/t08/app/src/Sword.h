#pragma once

#include "Sword.h"
#include "ImperialSoldier.h"
#include "Axe.h"

class Sword final {
public:
    Sword(int damage);
    int getDamage() const;
private:
    const int m_damage;
};
