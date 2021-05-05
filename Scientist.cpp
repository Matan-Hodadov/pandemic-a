#include "Scientist.hpp"

// #include "Player.hpp"

namespace pandemic
{
    Scientist::Scientist(Board& board, City city, uint cards_num) : Player(board, city)
    {
        this->cards_num = cards_num;
    }

    Scientist::~Scientist()
    {

    }
}