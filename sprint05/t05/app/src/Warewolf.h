#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>

class Creature {
public:
    Creature();
    ~Creature();
};

class Human : virtual public Creature {
public:
    Human() = default;
    ~Human() = default;
};

class Wolf : virtual public Creature {
public:
    Wolf() = default;
    ~Wolf() = default;
};


class Warewolf : public Wolf, public Human {
public:
    Warewolf();
    ~Warewolf();
};