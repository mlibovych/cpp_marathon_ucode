#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

void CheckEnd (std::stringstream& ss);

void CheckEnd (std::stringstream& ss, std::string& type);

void CheckItemType (const std::string& type);

void CheckItemOccurrence (const std::string& type, std::vector<std::string>& inventory);

void CheckSize (std::vector<std::string>& inventory);

void Insert(const std::string& type, std::vector<std::string>& inventory);

void Remove(const std::string& type, std::vector<std::string>& inventory);

void Show(const std::vector<std::string>& inventory);

void Help(void);

void CheckCommand (bool& process, std::stringstream& ss,
                   std::vector<std::string>& inventory);