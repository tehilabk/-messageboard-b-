#include "Board.hpp"
#include "Direction.hpp" 
#include <string>
#include <map>
#include <iostream>
using namespace std;
namespace ariel 
{
    //constructor
    Board::Board(){
        this->min_col=0;
        this->min_row=0; 
        this->max_col=0;
        this->max_row=0;
    }

    void Board::post(u_int row, u_int col, Direction direction, std::string msg){

        //check if first post
        if (this->MyBoard.empty()){
            this->min_row=row;
            this->min_col=col;
        }

        u_int length = msg.length();

        //post horizental 
        if(direction==Direction::Horizontal){

        //set board bounds
            this->max_row = max(this->max_row, row);
            this->max_col = max(this->max_col, col+length);
            this->min_row = min(this->min_row, row);
            this->min_col = min(this->min_col, col);

        //post on board
            for(u_int i=0 ;i<length;i++){
                this->MyBoard[row][col] = msg.at(i);
                col++;
            }
        } 

        //post vertical
        else if(direction == Direction::Vertical){

        //set board bounds
            this->max_row = max(this->max_row, row+length);
            this->max_col = max(this->max_col, col);
            this->min_row = min(this->min_row, row);
            this->min_col = min(this->min_col, col);

        //post on board
            for(u_int i=0 ;i<length;i++){
                this->MyBoard[row][col] = msg.at(i);
                row++;
            }
         }
    }

     std::string Board::read(u_int row, u_int col, Direction direction, u_int length){
       
        string msg;
        //read horizontal
        if(direction == Direction::Horizontal){
            for(uint i=0; i<length; i++){
                try {
                    msg += this->MyBoard.at(row).at(col);} 
                catch(const out_of_range) {
                    msg += '_';    
                }
                col++;
            }
        }
        //read vertical
        else if(direction == Direction::Vertical){  
              for(uint i=0; i<length; i++){
                try {
                    msg += this->MyBoard.at(row).at(col);} 
                catch(const out_of_range){
                    msg += '_';    
                }
                row++;
            }
        }    
        return msg;
    
    }

    void Board::show(){
         for (uint i = this->min_row-1; i <= this->max_row; i++) {
            for (uint j = this->min_col-1; j <= this->max_col+1; j++) {
                try {
                    cout << this->MyBoard.at(i).at(j);} 
                catch(const out_of_range){
                    cout << '_';    
                }
            }
            cout << "\n";
        } 
    }
}