#pragma once

#include <string>
#include <unordered_set>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

//#include <algorithm>
//include <list>
// #include "Cards.hpp"   //maybe add this

namespace pandemic
{
    class Player
    {
        protected:
        Board* board;
        City current_city;
        uint cards_num;
        std::unordered_set<City> owned_cards;

        

        public:
        Player(Board& b, City city);
        Player(Board& b, City city, int cards);
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);

        virtual std::string role() const = 0;
        Player& take_card(City city);
        Player& throw_card(City city);

    };
}