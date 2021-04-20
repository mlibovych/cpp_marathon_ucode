#include "libmove.h"

int main(int argc, char** argv) {
    std::vector<std::string> names;

    names.reserve(argc - 1);
    if (argc == 1) {
        std::cerr << "usage: ./moveAlong [args]" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        names.push_back(argv[i]);
    }
    for (auto& it : names) {
        std::string str(it.size(), 'a');
        std::transform(it.begin(), it.end(), str.begin(), (int (*)(int))std::tolower);
        if (str.find("merce") != std::string::npos
           || str.find("emer") != std::string::npos
           || str.find("jim") != std::string::npos) {
            std::cout << it << ", move along!" << std::endl;
        }
    }
}
