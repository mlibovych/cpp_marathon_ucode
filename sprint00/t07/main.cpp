#include "libInventoryManager.h"

int main() {
    std::vector<std::string> inventory;
    bool process = 1;

    inventory.reserve(12);
    while (process) {
        try {
            std::string line;
            std::stringstream ss;

            std::cout << "Enter command:> ";
            std::getline(std::cin, line);
            ss << line;
            CheckCommand(process, ss, inventory);
        }
        catch (std::exception& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
}
