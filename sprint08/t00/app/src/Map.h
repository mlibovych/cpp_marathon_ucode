#pragma once

#include <memory>

class Player;

class Map final {
public:
   Map(size_t width, size_t height, std::shared_ptr<Player>& player);
   ~Map() = default;

   void outputMap() const;
   size_t width() const;
   size_t height() const;

private:
   void generateMap();

   const size_t m_width{0};
   const size_t m_height{0};
   std::shared_ptr<Player> m_player;
   std::unique_ptr<char[]> m_map;
};

// 4 * 3
// arr[]

// 5 = 1c, 1r
// arr = {0, 1, 2, 3,
//        4, 5, 6, 7,
//        8, 9, 10, 11}
