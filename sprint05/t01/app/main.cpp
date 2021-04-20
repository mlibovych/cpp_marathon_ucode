#include "Draugr.h"

static void CheckArgs(int argc, char** argv) {
    if (argc < 2 || argc > 4) {
        throw std::runtime_error("usage: ./draugr [shoutNumber] [health] [frostResist]");
    }
    if (std::stoi(argv[1]) < 0 || std::stoi(argv[1]) > 8) {
        throw std::runtime_error("Invalid shoutNumber");
    }
}

int main(int argc, char** argv) {
    try {
        CheckArgs(argc, argv);
        if (argc == 2) {
            Draugr Olaf;
            Olaf.shoutPhrase(std::stoi(argv[1]));
        }
        else if (argc == 3) {
            Draugr Ulfrik(std::stod(argv[2]), 50);
            Ulfrik.shoutPhrase(std::stoi(argv[1]));
            Draugr Bertold(std::stoi(argv[2]));
            Bertold.shoutPhrase(std::stoi(argv[1]));
        }
        else {
            Draugr Gatrik(std::stod(argv[2]), std::stoi(argv[3]));
            Gatrik.shoutPhrase(std::stoi(argv[1]));
        }
    }
    catch (std::runtime_error& re) {
        std::cerr << re.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cerr << "Error" << std::endl;
    }
}