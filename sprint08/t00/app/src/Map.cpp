#include <iostream>
#include <random>

#include "Map.h"
#include "Player.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player>& player) :
         m_width(width), m_height(height), m_player(player) {
    generateMap();
}

size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}

void Map::outputMap() const {
    for (size_t rows = 0; rows < m_height; ++rows) {
        for (size_t cols = 0; cols < m_width; ++cols) {
            if (cols == m_player->posX() && rows == m_player->posY()) {
                std::cout << m_player->getIdentifier();
            }
            else {
                std::cout << *(m_map.get() + rows * m_width + cols);
            }
            if (cols < m_width - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Map::generateMap() {
    size_t dimension = m_width * m_height;
    m_map = std::make_unique<char[]>(dimension);
    for (size_t rows = 0; rows < m_height; ++rows) {
        for (size_t cols = 0; cols < m_width; ++cols) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 100);
            int rand = dis(gen);
            char c;

            if (rand < 33) {
                c = '.';
            }
            else if (rand < 66) {
                c = '@';
            }
            else {
                c = 'T';
            }
            *(m_map.get() + rows * m_width + cols) = c;
        }
    }
}