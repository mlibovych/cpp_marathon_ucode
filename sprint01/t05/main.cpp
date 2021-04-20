#include "src/libsrc.h"

int main(int argc, char** argv) {
    try {
        std::forward_list<std::string> flist;

        CheckArgs(argc);
        OpenFile(argv, flist);
        RemoveCBL(flist);
        ReplaceLong(flist);
        ReplaceShort(flist);
        Unicate(flist);
        ReversePrint(flist, argv);
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
}
