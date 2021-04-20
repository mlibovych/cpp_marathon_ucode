#include "dwemerCalculator.h"

int main(void) {
    Calc calc;

    while (1) {
        try {
            std::string line;

            std::cout << ":>";
            std::getline(std::cin, line);
            if (line == "quit") {
                break;
            }
            CheckCommand(line, calc);
        }
        catch (std::exception& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
}