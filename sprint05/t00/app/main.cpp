#include "Draugr.h"

int main(int argc, char** argv) {
    Draugr Olaf;

    try {
        if (argc != 2) {
            throw std::runtime_error("usage: ./draugr [shoutNumber]");
        }
        Olaf.shoutPhrase(std::stoi(argv[1]));
    }
    catch (std::runtime_error& re) {
        std::cerr << re.what() << std::endl;
    }
    catch (std::invalid_argument& ia) {
        std::cerr << "Invalid shoutNumber" << std::endl;
    }
}