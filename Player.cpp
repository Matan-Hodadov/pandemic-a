#include "Player.hpp"

// #include "City.hpp"
// #include "Color.hpp"

using namespace std;

namespace pandemic
{
    Player& Player::take_card(City city)
    {
        this->owned_cards.insert(city);
        return (*this);
    }

    Player& Player::throw_card(City city)
    {
        if(this->owned_cards.find(city) != this->owned_cards.end())
        {
            owned_cards.erase(city);
        }
        return (*this);
    }

    Player::Player(Board& b, City current_city)
    {
        this->board = &b;
        this->current_city = current_city;
    }

    Player::Player(Board& b, City current_city,int num_cards)
    {
        this->board = &b;
        this->current_city = current_city;
        for (size_t i = 0; i < num_cards; i++)
        {
            this->take_card(current_city);
        }
    }
    Player& Player::drive(City city)
    {
        return *this;
    }
    Player& Player::fly_direct(City city)
    {
        return *this;
    }
    Player& Player::fly_charter(City city)
    {
        return *this;
    }
    Player& Player::fly_shuttle(City city)
    {
        return *this;
    }
    Player& Player::build()
    {
        return *this;
    }
    Player& Player::discover_cure(Color color)
    {
        return *this;
    }
    Player& Player::treat(City city)
    {
        return *this;
    }
}