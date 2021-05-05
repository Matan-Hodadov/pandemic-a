#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        public:
        Scientist(Board& board, City city, uint cards_num = 4);
        ~Scientist();

        std::string role() const
        {
            return "Scientist";
        }
    };
}