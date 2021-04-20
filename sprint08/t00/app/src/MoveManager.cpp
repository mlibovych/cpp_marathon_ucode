#include <map>
#include <utility>
#include <iostream>
#include <regex>

#include "MoveManager.h"
#include "Player.h"
#include "Map.h"

MoveManager::MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map) :
                         m_map(map), m_player(player) {}

bool MoveManager::checkMove(Direction dir) const {
    std::map<Direction, std::pair<int, int>> dir_map {
        {Direction::Up, {0, -1}},
        {Direction::Down, {0, 1}},
        {Direction::Left, {-1, 0}},
        {Direction::Right, {1, 0}},
    };
    int x = static_cast<int>(m_player->posX());
    int y = static_cast<int>(m_player->posY());

    if (x + dir_map[dir].first >= 0 && x + dir_map[dir].first < static_cast<int>(m_map->width())
        && y + dir_map[dir].second >= 0 && y + dir_map[dir].second < static_cast<int>(m_map->height())) {
            m_player->movePlayer(dir);
            return 1;
    }
    return 0;
}

void MoveManager::processInputAndMove(const std::string& inputStr) {
    Direction dir;

    if (!std::regex_match(inputStr, std::regex("[//s]*[lrude][//s]*"))) {
        std::cerr << "Invalid input" << std::endl;
        return;
    }
    if (inputStr == "e") {
        exit(0);
    }
    else if (inputStr == "l") {
        dir = Direction::Left;
    }
    else if (inputStr == "r") {
        dir = Direction::Right;
    }
    else if (inputStr == "u") {
        dir = Direction::Up;
    }
    else if (inputStr == "d") {
        dir = Direction::Down;
    }
    else {
        std::cerr << "Invalid input" << std::endl;
        return;
    }
    if (!checkMove(dir)) {
        std::cerr << "Invalid direction" << std::endl;
    }
}