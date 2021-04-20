#pragma once
#include <iostream>

#include "Soldier.h"
#include "Sword.h"
#include "StormcloakSoldier.h"

class Sword;
class StormcloakSoldier;

class ImperialSoldier final : public Soldier  {
public:
    ImperialSoldier();
    ~ImperialSoldier();
};