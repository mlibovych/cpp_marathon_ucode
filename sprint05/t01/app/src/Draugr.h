#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Draugr {
    double m_health;
    const int m_frostResist;
public:
    Draugr();
    explicit Draugr(int frostResist);
    explicit Draugr(double health, int frostResist);

    void shoutPhrase(int shoutNumber) const;
};