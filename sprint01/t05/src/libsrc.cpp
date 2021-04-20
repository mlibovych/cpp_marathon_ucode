#include "libsrc.h"

void CheckArgs(int argc) {
    if (argc != 2) {
        throw std::invalid_argument("usage: ./stdAlgoV2 [file_name]");
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

void RemoveCBL(std::forward_list<std::string>& flist) {
    flist.remove_if([](std::string& str) {
        return str.find('c') != std::string::npos
               || str.find('b') != std::string::npos
               || str.find('l') != std::string::npos;
    });
}

void ReplaceLong(std::forward_list<std::string>& flist) {
    std::replace_if(flist.begin(), flist.end(), [](std::string& str) {
        return str.length() > 10;
    }, "Long One");
}

void ReplaceShort(std::forward_list<std::string>& flist) {
    std::replace_if(flist.begin(), flist.end(), [](std::string& str) {
        return str.length() < 4;
    }, "Short One");
}

void Unicate(std::forward_list<std::string>& flist) {
    flist.sort();
    flist.unique();
}

void ReversePrint(std::forward_list<std::string>& flist, char** argv) {
    std::string str(argv[1]);
    std::string name = {str.begin(), str.begin() + str.find('.')};
    std::string ext = {str.begin() + str.find('.'), str.end()};

    flist.reverse();
    std::ofstream output(name + "_mod" + ext);
    for (const auto& it : flist) {
        output << it << std::endl;
    }
}