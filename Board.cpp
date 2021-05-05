#include "Board.hpp"
#include <ostream>

#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    Board::Board()
    {
        for(int i = 0; i < 48;i++)
        {

            this->city_diseaselvl[(City)i] = 0;
        }
    }

    int& Board::operator [] (City city)
    {
        return this->city_diseaselvl[city];
    }

    std::ostream& operator << (std::ostream& os, const Board& board)
    {
        return os;
    }

    bool Board::is_clean()
    {
        for(int i = 0; i < 48;i++)
        {
            if (this->city_diseaselvl[(City)i] > 0)
            {
                return false;
            }
        }   
        return true;
    }

    void Board::remove_cures()
    {
        this->city_medicine.clear();
    }
}