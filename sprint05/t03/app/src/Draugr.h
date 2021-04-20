#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>

class Draugr {
    std::string m_name;
    double m_health;
    const int m_frostResist;
public:
    Draugr();
    explicit Draugr(int frostResist);
    explicit Draugr(double health, int frostResist);
    Draugr(Draugr& other) = delete;
    Draugr(Draugr&& other) = delete;

    void shoutPhrase(int shoutNumber) const;
    void setName(const std::string&& name);
};