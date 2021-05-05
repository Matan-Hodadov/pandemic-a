#include "Dispatcher.hpp"

// #include "Player.hpp"
using namespace std;

namespace pandemic
{
    Dispatcher::Dispatcher(Board &board, City city) : Player(board, city)
    {
    }
    Dispatcher::~Dispatcher()
    {
    }

    Player& Dispatcher::fly_direct(City dest_city)  //need to do this 
    {
       return (*this);
    }

}