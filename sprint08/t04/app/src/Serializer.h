#pragma once

#include <fstream>
#include <string>

class Serializer {
 public:
    template<class T>
    void serialize(const T* object, const std::string& fileName) {
        std::ofstream output;

        output.open(fileName);
        if (!output.is_open()) {
            throw std::invalid_argument("Ofile");
        }
        output.write(reinterpret_cast<const char *>(object), sizeof(T));
    }

    template<class T>
    T deserialize(const std::string& fileName) {
        T res;
        std::ifstream input;

        input.open(fileName);
        if (!input.is_open()) {
            throw std::invalid_argument("Ifile");
        }
        input.read(reinterpret_cast<char *>(&res), sizeof(T));

        return res;
    }
};
