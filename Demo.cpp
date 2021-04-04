/**
 * simple program for message-board exercise.
 * 
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;


int boardOperations(){
    u_int row, col, d, length;
    int keep;
    string post;
    Direction dir;
    static ariel::Board board;
    	
    int operation;
    cin >> operation;
    switch (operation)  {
        case 1:
            cout <<"enter row:"<< endl;
            cin >> row;
            cout << endl <<"now enter collumn:";
            cin >> col;
            cout << endl <<"if you want post to be horizontal enter 1, else enter 0:";
            cin >> d;
            d == 1? dir=Direction::Horizontal : dir=Direction::Vertical; 
            cout << endl <<"write your post:";
            cin >> post;
            board.post(row, col, dir, post);
            keep = 1;
            break;
    
        case 2:   
            cout <<"enter row:"<< endl;
            cin >> row;
            cout << endl <<"now enter collumn:";
            cin >> col;
            cout << endl <<"if you want post to be horizontal enter 1, else enter 0:";
            cin >> d;
            d == 1? dir=Direction::Horizontal : dir=Direction::Vertical; 
            cout<<"how much do you want to read? :" << endl;
            cin >> length;
            cout << board.read(row, col, dir, length) << endl;
            keep = 1;
            break;
        case 3:
            board.show();
            keep = 1;
            break;
            
        case 0:
            keep = 0;
            break;
            
        default:
            cout <<"illegal operation code. please try again";
            keep = 1;
            break;
    }
    return keep;
}
int main() { 
    int keepGoing=1;
	cout<< "\nWellcome to the post board, please choose what you want to do:" << endl
	    << "to post enter '1'\nto read enter '2' \nto show post enter '3'\nenter 0 to exit program."<<endl;
	while(keepGoing){
        keepGoing = boardOperations();
        cout<< "\nplease choose what you want to do:" << endl
	    << "to post enter '1'\nto read enter '2' \nto show post enter '3'\nenter 0 to exit program."<<endl;
	}	 
	return 0;
}