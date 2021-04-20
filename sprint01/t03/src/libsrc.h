#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <sstream>
#include <utility>
#include <list>
#include <ctime>
#include <chrono>
#include <thread>
#include <random>

enum class Gender {
    Male,
    Female
};
struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

Rabbit Create(std::random_device& rd);

void AddYear(std::list<Rabbit>& rabbits);

void Reproduction(std::list<Rabbit>& rabbits, std::random_device& rd);

void Print(std::list<Rabbit>& rabbits);

void Bite(std::list<Rabbit>& rabbits);

void Death(std::list<Rabbit>& rabbits);