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

void CheckArgs(int argc);

void OpenFile(char** argv,
              std::multiset<std::string>& fmultiset);

void SortedPrint(char** argv,
                 std::multiset<std::string>& fmultiset);