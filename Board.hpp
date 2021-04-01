#pragma once
#include "Direction.hpp"
#include <string>
#include <map>


namespace ariel
{
    class Board
    {
        std::map<u_int, std::map<u_int, char>> MyBoard; // <row,<col,msg>>
        u_int min_col;
        u_int min_row; 
        u_int max_col;
        u_int max_row; 
       
    public:
    
        Board();
        ~Board(){};
        void post(u_int row, u_int column, Direction direction,  std::string msg);

        std::string read(u_int row, u_int column, Direction direction, u_int length);

        void show();
    };

}