#include <algorithm>
#include <iostream>
#include <string>

#include "Map.h"
#include "MoveManager.h"
#include "Player.h"

int main(int argc, char** argv) {
    try {
        int width, heigth;
        std::string command;

        if (argc != 3) {
            throw std::runtime_error("usage");
        }
        size_t pos;
        width = std::stoi(argv[1], &pos);
        if (pos != std::char_traits<char>::length(argv[1])) {
            throw std::invalid_argument("size");
        }
        heigth = std::stoi(argv[2], &pos);
        if (pos != std::char_traits<char>::length(argv[2])) {
            throw std::invalid_argument("size");
        }
        if (width < 5 || width > 20 || heigth < 5 || heigth > 20) {
            throw std::invalid_argument("size");
        }
        std::shared_ptr<Player> player_ptr = std::make_shared<Player>();
        std::shared_ptr<Map> map_ptr = std::make_shared<Map>(width, heigth, player_ptr);
        std::unique_ptr<MoveManager> manager_ptr = std::make_unique<MoveManager>(player_ptr, map_ptr);
        while (1) {
            map_ptr->outputMap();
            std::cout << ":> " << std::flush;
            std::cin >> command;
            manager_ptr->processInputAndMove(command);
        }


    }
    catch(std::runtime_error& re) {
        std::cerr << "usage: ./smartPointers [width] [height]" << std::endl;
    }
    catch(std::invalid_argument& ia) {
        std::cerr << "Invalid map size" << std::endl;
    }
    return 0;
}
