#include "FieldDoctor.hpp"

// #include "Player.hpp"

namespace pandemic
{
    FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city)
    {
    }
    FieldDoctor::~FieldDoctor()
    {
    }

    bool FieldDoctor::can_treat(City city)  //need to do this 
    {    
        return true;
    }   
}