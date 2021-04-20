#include "src/libsrc.h"

int main(int argc, char** argv) {
    try {
        std::multiset<std::string> fmultiset;

        CheckArgs(argc);
        OpenFile(argv, fmultiset);
        SortedPrint(argv, fmultiset);
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
}

