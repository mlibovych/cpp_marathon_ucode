#include "Draugr.h"

static void CheckArgs(int argc, char** argv, std::string& name1, std::string& name2) {
    std::stringstream ss;

    if (argc < 4 || argc > 5) {
        throw std::runtime_error("usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]");
    }
    if (std::stoi(argv[1]) < 0 || std::stoi(argv[1]) > 8) {
        throw std::runtime_error("Invalid shoutNumber");
    }
    ss << argv[2];
    std::getline(ss, name1, ',');
    std::getline(ss, name2, ',');
    if (name1.empty() || name2.empty() || !ss.eof()) {
        throw std::runtime_error("Invalid names");
    }
}

int main(int argc, char** argv) {
    std::string name1, name2;

    try {
        CheckArgs(argc, argv, name1, name2);
        if (argc == 4) {
            Draugr Draugr1(std::stod(argv[3]), 50);
            Draugr1.setName(std::move(name1));
            Draugr1.shoutPhrase(std::stoi(argv[1]));
            Draugr Draugr2(Draugr1);
            Draugr2.setName(std::move(name2));
            Draugr2.shoutPhrase(std::stoi(argv[1]));
        }
        else {
            Draugr Draugr1(std::stod(argv[3]), std::stoi(argv[4]));
            Draugr1.setName(std::move(name1));
            Draugr1.shoutPhrase(std::stoi(argv[1]));
            Draugr Draugr2(std::move(Draugr1));
            Draugr2.setName(std::move(name2));
            Draugr2.shoutPhrase(std::stoi(argv[1]));
        }
    }
    catch (std::runtime_error& re) {
        std::cerr << re.what() << std::endl;
    }
    catch (std::invalid_argument& ia) {
        std::cerr << "Error" << std::endl;
    }
    catch (std::out_of_range& oor) {
        std::cerr << "Error" << std::endl;
    }
}