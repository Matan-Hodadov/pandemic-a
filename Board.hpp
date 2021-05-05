#pragma once

#include <ostream>
#include <unordered_map>
#include <unordered_set>

#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
        private:
        std::unordered_map<City, int> city_diseaselvl;
        std::unordered_set<City> city_station;
        std::unordered_set<Color> city_medicine;
        // std::unordered_map<City, bool> city_station;
        // std::unordered_map<Color, bool> city_medicine;

        public:
        Board();
        int& operator [] (City city);
        friend std::ostream& operator << (std::ostream& os, const Board& board);
        // friend std::ostream& operator << (std::ostream& os, use 'this' instead);
        bool is_clean();
        void remove_cures();
    };
}
