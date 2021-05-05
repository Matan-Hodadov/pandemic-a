#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
        public:
        Medic(Board& board, City city);
        ~Medic();

        std::string role() const
        {
            return "Medic";
        }
    };
}