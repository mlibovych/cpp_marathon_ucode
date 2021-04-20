#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "../Food/FoodItem.h"

class AbstractWizard {
    const std::string m_name;
public:
    AbstractWizard(std::string name);
    virtual ~AbstractWizard() = default;
protected:
    virtual FoodType deductFoodType(FoodItem food) = 0;
};


class MightyWizard : public AbstractWizard {
    std::map<FoodType, std::string> types = {
        {FoodType::ApplePie, "Apple pie"},
        {FoodType::SweetRoll, "SweetRoll"},
        {FoodType::PoisonedFood, "Poison"},
        {FoodType::HoneyNut, "Honey nut"},
        {FoodType::Invalid, "<unknown>"}
    };
public:
    MightyWizard(std::string name);
    ~MightyWizard() = default;

    FoodType deductFoodType(FoodItem food) override;
    void checkFood(FoodItem food);
    void checkFood(FoodItem* food);
};

