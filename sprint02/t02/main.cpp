#include "src/libsrc.h"

int main() {
    std::map<std::string, std::string> library;
    bool process = 1;

    while (process) {
        try {
            std::string line;
            std::stringstream ss;

            std::cout << "enter command:> ";
            std::getline(std::cin, line);
            ss << line;
            CheckCommand(process, ss, library);
        }
        catch (std::exception& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
}

