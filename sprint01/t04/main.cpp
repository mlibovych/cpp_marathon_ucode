#include "src/libsrc.h"

int main(int argc, char** argv) {
    try {
        std::forward_list<std::string> flist;

        CheckArgs(argc);
        OpenFile(argv, flist);
        CheckSize(flist);
        CheckRich(flist);
        Check15(flist);
        CheckEndVel(flist);
        CheckWithoutMel(flist);
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
}
