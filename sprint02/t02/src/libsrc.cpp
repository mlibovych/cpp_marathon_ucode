#include "libsrc.h"

void CheckEnd(std::stringstream& ss) {
    if (!ss.eof()) {
        throw std::runtime_error("invalid command");
    }
}

std::pair<std::string, std::ifstream> CheckBook(std::stringstream& ss, bool check) {
    std::string book;
    std::ifstream input;

    ss >> book;
    if (book.empty()) {
        throw std::runtime_error("invalid command");
    }
    CheckEnd(ss);
    book.insert(0, "./library/");
    input.open(book);
    if (check && !input.is_open()) {
        throw std::invalid_argument("invalid book");
    }
    return std::make_pair(book.substr(10), std::move(input));
}

void Add(std::map<std::string, std::string>& library,
         std::pair<std::string, std::ifstream>  book) {
    std::string text, tmp;
    while (std::getline(book.second, tmp)) {
        text += tmp;
        if (!book.second.eof()) {
            text += "\n";
        }
    }
    library[book.first] = text;
    if (library.count(book.first)) {
        std::cout << book.first << " added" << std::endl;
    }
}

void Delete(std::map<std::string, std::string>& library,
         std::pair<std::string, std::ifstream>  book) {
    std::string text, tmp;
    if (!library.count(book.first)) {
        throw std::invalid_argument("invalid book");
    }
    library.erase(book.first);
    if (!library.count(book.first)) {
        std::cout << book.first << " deleted" << std::endl;
    }
}

void Read(std::map<std::string, std::string>& library,
         std::pair<std::string, std::ifstream>  book) {
    if (!library.count(book.first)) {
        throw std::invalid_argument("invalid book");
    }
    std::cout << library[book.first] << std::endl;
}

void List(const std::map<std::string, std::string>& library) {
    for (const auto& [key, value] : library) {
        std::cout << key << std::endl;
    }
}

void CheckCommand(bool& process, std::stringstream& ss,
                  std::map<std::string, std::string>& library) {
    std::string command;

    ss >> command;
    if (command == "quit") {
        CheckEnd(ss);
        std::cout << "bye" << std::endl;
        process = 0;
    }
    else if (command == "add") {
        Add(library, CheckBook(ss, 1));
    }
    else if (command == "delete") {
        Delete(library, CheckBook(ss, 0));
    }
    else if (command == "read") {
        Read(library, CheckBook(ss, 0));
    }
    else if (command == "list") {
        CheckEnd(ss);
        List(library);
    }
    else {
        throw std::runtime_error("invalid command");
    }
}