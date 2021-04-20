#include "libsrc.h"

void CheckArgs(int argc) {
    if (argc != 2) {
        throw std::invalid_argument("usage: ./tesLibrary [file_name]");
    }
}

void Find (const std::string& line, std::multimap<std::string, std::string>& fmultimap) {
    std::smatch match;
    std::string author, title;
    auto it = find(line.begin(), line.end(), ':');

    std::regex_search(line.begin(), it, match, std::regex("\"[!|\\s|#-~]+\""));
    author = match.str();
    author.erase(author.begin());
    author.erase(author.end() - 1);
    std::regex_search(it, line.end(), match, std::regex("\"[!|\\s|#-~]+\""));
    title = match.str();
    title.erase(title.begin());
    title.erase(title.end() - 1);
    fmultimap.insert({author, title});
}


void GetNames(std::ifstream& input, std::multimap<std::string, std::string>& fmultimap) {
    std::string line;

    int i = 1;
    while (!input.eof()) {
        std::getline(input, line);
        if (!std::regex_match (line,
            std::regex("[\\s]*\"[!|\\s|#-~]+\"[\\s]*:[\\s]*\"[!|\\s|#-~]+\"[\\s]*"))) {
            throw std::invalid_argument("Line " + std::to_string(i) + " is invalid");
        }
        Find(line, fmultimap);
        ++i;
    }
}

void Print(const std::multimap<std::string, std::string>& fmultimap) {
    std::string tmp;
    int count = 1;

    for (const auto& [key, val] : fmultimap) {
        if (key != tmp) {
            count = 1;
            std::cout << key << ":" << std::endl;
        }
        tmp = key;
        std::cout << " " << count << ": " << val << std::endl;
        ++count;
    }
}