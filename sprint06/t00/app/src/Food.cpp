#include "Food/FoodItem.h"
#include "Food/ApplePie.h"
#include "Food/HoneyNut.h"
#include "Food/PoisonedFood.h"
#include "Food/SweetRoll.h"

FoodItem::FoodItem(FoodType type) : m_type(type) {};

FoodType FoodItem::GetFoodType() {
    return m_type;
}

ApplePie::ApplePie() : FoodItem(FoodType::ApplePie) {};

HoneyNut::HoneyNut() : FoodItem(FoodType::HoneyNut) {};

PoisonedFood::PoisonedFood() : FoodItem(FoodType::PoisonedFood) {};

SweetRoll::SweetRoll() : FoodItem(FoodType::SweetRoll) {};