#include "src/libsrc.h"

int main(int argc, char** argv) {
    try {
        std::multimap<std::string, std::string> fmultimap;
        std::ifstream input;

        CheckArgs(argc);
        input.open(argv[1]);
        if (!input.is_open() || input.eof()) {
            throw std::invalid_argument("error");
        }
        GetNames(input, fmultimap);
        Print(fmultimap);
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
}

