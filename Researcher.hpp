#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Researcher : public Player
    {
        public:
        Researcher(Board& board, City city);
        ~Researcher();

        std::string role() const
        {
            return "Researcher";
        }
    };
}