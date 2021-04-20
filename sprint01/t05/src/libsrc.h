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

void RemoveCBL(std::forward_list<std::string>& flist);

void ReplaceLong(std::forward_list<std::string>& flist);

void ReplaceShort(std::forward_list<std::string>& flist);

void Unicate(std::forward_list<std::string>& flist);

void ReversePrint(std::forward_list<std::string>& flist, char** argv);