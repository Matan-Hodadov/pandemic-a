#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
        public:
        Virologist(Board& board, City city);
        ~Virologist();

        std::string role() const
        {
            return "Virologist";
        }

        Player& treat(City);

        protected:
        bool can_treat(City);
    };
}