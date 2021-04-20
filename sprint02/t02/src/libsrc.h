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

void CheckEnd(std::stringstream& ss);

std::pair<std::string, std::ifstream> CheckBook(std::stringstream& ss, bool check);

void Add(std::map<std::string, std::string>& library,
         std::pair<std::string, std::ifstream>  book);

void Delete(std::map<std::string, std::string>& library,
         std::pair<std::string, std::ifstream>  book);

void Read(std::map<std::string, std::string>& library,
         std::pair<std::string, std::ifstream>  book);

void List(const std::map<std::string, std::string>& library);

void CheckCommand (bool& process, std::stringstream& ss,
                   std::map<std::string, std::string>& library);