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
            // City city = (City)i;
            this->city_diseaselvl[(City)i] = 0;
            // this->city_station[city] = false;
        }
        // this->city_medicine[Yellow] = false;
        // this->city_medicine[Blue] = false;
        // this->city_medicine[Red] = false;
        // this->city_medicine[Black] = false;
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
            // City city = (City)i;
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
        // this->city_medicine[Yellow] = false;
        // this->city_medicine[Blue] = false;
        // this->city_medicine[Red] = false;
        // this->city_medicine[Black] = false;
    }
}