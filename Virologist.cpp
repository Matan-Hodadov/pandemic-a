#include "Virologist.hpp"

// #include "Player.hpp"
using namespace std;

namespace pandemic
{
    Virologist::Virologist(Board& board, City city) : Player(board, city)
    {
    }
    Virologist::~Virologist()
    {
    }

    bool Virologist::can_treat(City city)
    {
        return (*board)[city] > 0;
    }
    Player &Virologist::treat(City city)
    {
        if (city != this->current_city)
        {
            auto card = owned_cards.find(city);
            if (card == owned_cards.end())
            {
                throw invalid_argument("You Don't have the required card");
            }
            owned_cards.erase(card);
        }
        Player::treat(city);
        return *this;
    }   
}