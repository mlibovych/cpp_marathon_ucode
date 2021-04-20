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
#include <fstream>
#include <set>
#include <forward_list>
#include <map>
#include <regex>

void CheckArgs(int argc);

void GetNames(std::ifstream& input, std::multimap<std::string, std::string>& fmultimap);

void Print(const std::multimap<std::string, std::string>& fmultimap);