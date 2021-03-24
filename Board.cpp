#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;



void ariel::Board::post(unsigned int row, unsigned int col, enum ariel::Direction dir, const string &msg){

    this->col=col;//temp fix for clang-tidy, once implemnted fully all will be ok;

}
std::string ariel::Board::read(unsigned int row, unsigned int col, enum ariel::Direction dir, int length){
    return "Not Yet";
}
std::string ariel::Board::show(){
    return "Not Yet";
}

