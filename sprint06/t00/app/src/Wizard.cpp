#include "Food/ApplePie.h"
#include "Food/HoneyNut.h"
#include "Food/PoisonedFood.h"
#include "Food/SweetRoll.h"
#include "Wizard/MightyWizard.h"

AbstractWizard::AbstractWizard(std::string name) : m_name(name) {}

FoodType AbstractWizard::deductFoodType(FoodItem food) {
    return food.GetFoodType();
}

MightyWizard::MightyWizard(std::string name) : AbstractWizard(name) {}

FoodType MightyWizard::deductFoodType(FoodItem food) {
    return AbstractWizard::deductFoodType(food);
}


void MightyWizard::checkFood(FoodItem food) {
    std::cout << types[deductFoodType(food)] << ". ";
    if (deductFoodType(food) == FoodType::HoneyNut
        || deductFoodType(food) == FoodType::SweetRoll) {
            std::cout << "Mmm, tasty";
        }
    else {
        std::cout << "Ugh, not again";
    }
    std::cout << "!" << std::endl;;
}

void MightyWizard::checkFood(FoodItem* food) {
    if (food == nullptr) {
        checkFood({FoodType::Invalid});
    }
    else {
        checkFood(*food);
    }
}