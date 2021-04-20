#include "libsrc.h"

Rabbit Create(std::random_device& rd) {
    Rabbit rabbit;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int gender = dis(gen);
    int vamp = dis(gen);

    rabbit.age = 0;
    rabbit.gender = (gender < 50) ? Gender::Female : Gender::Male;
    rabbit.isVampire = (vamp == 100) ? 1 : 0;
    if (rabbit.isVampire) {
        rabbit.gender = Gender::Female;
    }

    return rabbit;
}

void AddYear(std::list<Rabbit>& rabbits) {
    std::transform(rabbits.begin(), rabbits.end(), rabbits.begin(), [](Rabbit& rabbit) {
        ++rabbit.age;
        return rabbit;
    });
}

void Reproduction(std::list<Rabbit>& rabbits, std::random_device& rd) {
    int males = std::count_if(rabbits.begin(), rabbits.end(), [](Rabbit& rabbit) {
        return rabbit.isVampire == 0 && rabbit.gender == Gender::Male;
    });
    int females = std::count_if(rabbits.begin(), rabbits.end(), [](Rabbit& rabbit) {
        return rabbit.isVampire == 0 && rabbit.gender == Gender::Female;
    });
    for (int i = 0; i < std::min(males, females); ++i) {
        rabbits.push_back(Create(rd));
    }
}

void Print(std::list<Rabbit>& rabbits) {
    int males = std::count_if(rabbits.begin(), rabbits.end(), [](Rabbit& rabbit) {
    return rabbit.isVampire == 0 && rabbit.gender == Gender::Male;
    });
    int females = std::count_if(rabbits.begin(), rabbits.end(), [](Rabbit& rabbit) {
        return rabbit.isVampire == 0 && rabbit.gender == Gender::Female;
    });
    int vamps = std::count_if(rabbits.begin(), rabbits.end(), [](Rabbit& rabbit) {
        return rabbit.isVampire == 1;
    });

    std::cout << "Males: " << males << std::endl
                << "Females: " << females << std::endl
                << "Vampires: " << vamps << std::endl;
}

void Death(std::list<Rabbit>& rabbits) {
    rabbits.remove_if([](Rabbit& rabbit) {
        if ((rabbit.isVampire && rabbit.age > 8)
            || (!rabbit.isVampire && rabbit.age > 3)) {
            return 1;
        }
        return 0;
    });
}

void Bite(std::list<Rabbit>& rabbits) {
    int prem_vamps = std::count_if(rabbits.begin(), rabbits.end(), [](Rabbit& rabbit) {
        return rabbit.isVampire == 1 /*&& rabbit.gender == Gender::Female*/;
    });
    for (int i = 0; i < prem_vamps; ++i) {
        auto it = std::find_if(rabbits.begin(), rabbits.end(), [](Rabbit& rabbit) {
            return rabbit.isVampire == 0;
        });
        if (it == rabbits.end()) {
            break;
        }
        it->isVampire = 1;
        it->gender = Gender::Male;
    }
}