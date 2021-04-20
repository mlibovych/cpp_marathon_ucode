#include "libsrc.h"

void CheckArgs(int argc) {
    if (argc != 2) {
        throw std::invalid_argument("usage: ./countUniqueWords [file_name]");
    }
}

std::string GetString(char** argv) {
    std::string text, tmp;
    std::ifstream input;

    input.open(argv[1]);
    if (!input.is_open()) {
        throw std::invalid_argument("error");
    }
    while (std::getline(input, tmp)) {
        text += tmp + "\n";
    }
    return text;
}

void OpenFile(char** argv,
              std::multiset<std::string>& fmultiset) {
    std::string text;
    std::string::iterator first, second;

    text = GetString(argv);
    first = text.begin();
    second = text.begin();
    while (second != text.end()) {
        second = std::find_if(first, text.end(), [](char a) {
            return !std::isalnum(a) && a != '\'' && a != '-';
        });
        if (std::distance(first, second)) {
            fmultiset.insert({first, second});
        }
        first = second + 1;
    }
    if (!std::distance(fmultiset.begin(), fmultiset.end())) {
        throw std::invalid_argument("error");
    }
}


void SortedPrint(char** argv,
                 std::multiset<std::string>& fmultiset) {
    std::string new_file(argv[1]);
    std::ofstream output;
    std::string tmp;

    if (new_file.find('.') != std::string::npos) {
        new_file.insert(new_file.find('.'), "_mod");
    }
    else {
        new_file += "_mod";
    }
    output.open(new_file);
    for (const auto& it : fmultiset) {
        if (it != tmp) {
            output << it << ": " << fmultiset.count(it) << std::endl;
        }
        tmp = it;
    }
}