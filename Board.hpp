#pragma once
#include "Direction.hpp"
#include <string>


namespace ariel
{
    class Board
    {
       
    public:
    
        Board();

        void post(u_int row, u_int column, Direction direction,  std::string msg);

        std::string read(u_int row, u_int column, Direction direction, u_int length);

        void show();
    };

}