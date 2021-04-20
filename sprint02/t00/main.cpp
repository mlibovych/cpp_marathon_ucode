#include "src/libsrc.h"

int main(int argc, char** argv) {
    try {
        std::set<std::string> fset;

        CheckArgs(argc);
        OpenFile(argv, fset);
        SortedPrint(fset, argv);
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
}
