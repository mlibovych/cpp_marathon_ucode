#include <iostream>
#include <string>

#include "Serializer.h"
#include "SomeClass.h"

void deserialize(const std::string &path) {
    Serializer ser;

    if (path == "int") {
        auto obj = ser.deserialize<int>(path);
        std::cout << "Deserialized int: " << obj << std::endl;
    } else if (path == "float") {
        auto obj = ser.deserialize<float>(path);
        std::cout << "Deserialized float: " << obj << std::endl;
    } else {
        auto obj = ser.deserialize<SomeClass>(path);
        std::cout << "Deserialized ";
        obj.output();
        std::cout << std::endl;
    }
}

void serialize(const std::string &path, const std::string &val1, const std::string &val2, const std::string &val3) {
    Serializer ser;
    size_t pos;
    int intVal = std::stoi(val1, &pos);
    if (pos != val1.length()) {
        throw std::invalid_argument("int");
    }
    float floatVal = std::stof(val3, &pos);
    if (pos != val3.length()) {
        throw std::invalid_argument("float");
    }
    if (val2.size() != 1) {
        throw std::invalid_argument("char");
    }
    SomeClass som(intVal, val2[0], floatVal);

    ser.serialize<SomeClass>(&som, path);
    som.output();
    std::cout << " serialized" << std::endl;
}

void serialize(const std::string &path, const std::string &val) {
    Serializer ser;
    size_t pos;

    if (path == "int") {
        int intVal = std::stoi(val, &pos);
        if (pos != val.length()) {
            throw std::invalid_argument("int");
        }
        ser.serialize<int>(&intVal, path);
        std::cout << "int: " << intVal << " serialized" << std::endl;
    } else if (path == "float") {
        float floatVal = std::stof(val, &pos);
        if (pos != val.length()) {
            throw std::invalid_argument("float");
        }
        ser.serialize<float>(&floatVal, path);
        std::cout << "float: " << floatVal << " serialized" << std::endl;
    } else {
        throw std::invalid_argument("filename");
    }
}

int main(int argc, char** argv) {
    try {
        if (argc < 2 || argc > 5) {
            throw std::runtime_error("usage: ./serializer [arg1] [arg2] [arg3] [arg4]");
        }
        if (argc == 2) {
            deserialize(argv[1]);
        }
        else if (argc == 3) {
            serialize(argv[1],  argv[2]);
        }
        else if (argc == 5) {
            serialize(argv[1],  argv[2], argv[3], argv[4]);
        }
    }
    catch (std::runtime_error &re) {
        std::cerr << re.what() <<std::endl;
    }
    catch (std::invalid_argument &ia) {
        std::cerr << "error" <<std::endl;
    }
    return 0;
}
