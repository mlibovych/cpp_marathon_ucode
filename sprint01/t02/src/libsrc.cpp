#include "libsrc.h"

Town GetTown(const std::string& str, int idx) {
    std::istringstream ss(str);
    std::string name, tmp;
    int stamina, distance;
    size_t pos = 0;

    std::getline(ss, name, ',');
    if (name.empty() || std::find_if_not(name.begin(), name.end(), [](char a){
            return std::isalpha(a) || std::isspace(a) ;
        }) != name.end()) {
        throw std::invalid_argument(str);
    }
    std::getline(ss, tmp, ',');
    stamina = std::stoi(tmp, &pos);
    if (pos != tmp.length() || tmp[0] == ' ') {
        throw std::invalid_argument(str);
    }
    std::getline(ss, tmp, ',');
    distance = std::stoi(tmp, &pos);
    if (pos != tmp.length() || tmp[0] == ' ' || !ss.eof()) {
        throw std::invalid_argument(str);
    }
    return {name, stamina, distance, idx};
}

void GetTowns(std::deque<Town>& towns, int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        try {
            towns.push_back(GetTown(argv[i], i - 1));
        }
        catch (std::exception& ex) {
            throw std::invalid_argument(argv[i]);
        }
    }
    if (argc == 2) {
        throw std::runtime_error("Mission: Impossible");
    }
}

void GetPath(std::deque<Town>& towns, int argc) {
    for (int i = 0; i < argc - 1; ++i) {
        int res = 0;

        for (auto& town : towns) {
            res += town.stamina;
            res -= town.distnce;
            if (res < 0) {
                break;
            }
        }
        if (res >= 0) {
            return;
        }
        Town town = towns.front();
        towns.pop_front();
        towns.push_back(town);
    }
    throw std::runtime_error("Mission: Impossible");
}

void PrintPath(const std::deque<Town>& towns) {
    for (auto& town : towns) {
        std::cout << town.idx << ". " << town.name << std::endl;
    }
}