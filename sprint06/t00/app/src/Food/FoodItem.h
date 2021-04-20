#pragma once

enum class FoodType {
    ApplePie,
    HoneyNut,
    SweetRoll,
    PoisonedFood,
    Invalid
};

class FoodItem {
    FoodType m_type;
public:
    FoodItem(FoodType type);
    virtual ~FoodItem() = default;

    FoodType GetFoodType();
};


