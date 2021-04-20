#pragma once

#include <iostream>

#include "Soldier.h"
#include "Axe.h"
#include "ImperialSoldier.h"

class Axe;
class ImperialSoldier;

class StormcloakSoldier final : public Soldier {
public:
    StormcloakSoldier();
    ~StormcloakSoldier();
};