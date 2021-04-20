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
#include <forward_list>

void CheckArgs(int argc);

void OpenFile(char** argv, std::forward_list<std::string>& flist);

void CheckSize(const std::forward_list<std::string>& flist);

void CheckRich(const std::forward_list<std::string>& flist);

void Check15(const std::forward_list<std::string>& flist);

void CheckWithoutMel(const std::forward_list<std::string>& flist);

void CheckEndVel(const std::forward_list<std::string>& flist);