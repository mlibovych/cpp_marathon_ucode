#include "src/libsrc.h"

int main(int argc, char** argv) {
    std::deque<Town> towns;

    if (argc == 1) {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]" << std::endl;
        return 1;
    }
    try {
        GetTowns(towns, argc, argv);
        GetPath(towns, argc);
        PrintPath(towns);
    }
    catch (std::invalid_argument& ex) {
        std::cerr << "Argument " << ex.what() << " is not valid"<< std::endl;
    }
    catch (std::runtime_error& re) {
        std::cerr << re.what() << std::endl;
    }
}
