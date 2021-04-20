#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>

auto toInt(char* arg) {
    auto i = 0;
    auto sign_count = 0;

    while(1) {
        auto c = arg[i++];

        if (c == '\0') {
            break;
        }
        else if (!isnumber(c) && c != '+' && c != '-') {
            throw std::invalid_argument(arg);
        }
        else if (c == '+' || c == '-') {
            sign_count++;
        }
    }
    if (sign_count > 1) {
        throw std::invalid_argument(arg);
    }
    return std::stoi(arg);
}

auto toFloat(char* arg) {
    auto i = 0;
    auto sign_count = 0;
    auto period_count = 0;

    while(1) {
        auto c = arg[i++];

        if (c == '\0') {
            break;
        }
        else if (!isnumber(c) && c != '+' && c != '-' && c != '.') {
            throw std::invalid_argument(arg);
        }
        else if (c == '+' || c == '-') {
            sign_count++;
        }
        else if (c == '.') {
            period_count++;
        }
    }
    if (sign_count > 1 || period_count > 1) {
        throw std::invalid_argument(arg);
    }
    return std::stof(arg);
}


int main(int argc, char** argv) {
    int num = 0;

    if (argc != 5) {
        std::cerr << "usage: ./automaton [name] [level] [health] [stamina]" << std::endl;
        return 0;
    }
    try {
        auto Name = argv[1];
        ++num;
        auto Level = toInt(argv[2]);
        ++num;
        auto Health = toFloat(argv[3]);
        ++num;
        auto Stamina = toFloat(argv[4]);
        ++num;

        std::cout << "Name = " << Name << std::endl;
        std::cout << "Level = " << Level << std::endl;
        std::cout << "Health = " << Health << std::endl;
        std::cout << "Stamina = " << Stamina << std::endl;
    }
    catch (std::invalid_argument& ex) {
        std::cerr << "Invalid argument: " << argv[++num] << std::endl;
    }
}
