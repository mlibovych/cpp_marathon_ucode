#include "libsrc.h"

void CheckArgs(int argc) {
    if (argc != 2) {
        throw std::invalid_argument("usage: ./stdAlgoV1 [file_name]");
    }
}

void OpenFile(char** argv, std::forward_list<std::string>& flist) {
    std::string line;
    std::ifstream input;

    input.open(argv[1]);
    if (!input.is_open()) {
        throw std::invalid_argument("error");
    }
    while (std::getline(input, line)) {
        flist.push_front(line);
    }
    if (!std::distance(flist.begin(), flist.end())) {
        throw std::invalid_argument("error");
    }
}

void CheckSize(const std::forward_list<std::string>& flist) {
    std::cout << "size: " << std::distance(flist.begin(), flist.end()) << std::endl;
}

void CheckRich(const std::forward_list<std::string>& flist) {
    std::cout << "contains'rich': ";
    if (std::find_if(flist.begin(), flist.end(), [](const std::string& str){
            return str.find("rich") != std::string::npos;
        }) != flist.end()) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
    std::cout << std::endl;
}

void Check15(const std::forward_list<std::string>& flist) {
    std::cout << "none of lengths is 15: ";
    if (std::find_if(flist.begin(), flist.end(), [](const std::string& str){
            return str.length() == 15;
        }) != flist.end()) {
        std::cout << "false";
    }
    else {
        std::cout << "true";
    }
    std::cout << std::endl;
}

void CheckWithoutMel(const std::forward_list<std::string>& flist) {
    int size = std::count_if(flist.begin(), flist.end(), [](const std::string& str){
            return str.find("mel") == std::string::npos;
        });
    std::cout << "without'mel': " << size << std::endl;
}

void CheckEndVel(const std::forward_list<std::string>& flist) {
    std::cout << "all end with'vel': ";
    if (std::find_if(flist.begin(), flist.end(), [](const std::string& str){
            return str.find("vel") == std::string::npos
                   || str.find("vel") != str.length() - 3;
        }) != flist.end()) {
        std::cout << "false";
    }
    else {
        std::cout << "true";
    }
    std::cout << std::endl;
}