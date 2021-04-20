#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <sstream>
#include <utility>

struct Town {
    std::string name;
    int stamina;
    int distnce;
    int idx;
};

Town GetTown(const std::string& str, int idx);

void GetTowns(std::deque<Town>& towns, int argc, char** argv);

void GetPath(std::deque<Town>& towns, int argc);

void PrintPath(const std::deque<Town>& towns);