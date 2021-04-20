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
    void shoutPhrase(int shoutNumber) const;
};