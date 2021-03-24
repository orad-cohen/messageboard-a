
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
using namespace ariel;

namespace ariel{

    class Board{
        unsigned int row;
        unsigned int col;
        public:
            Board(unsigned int col =100, unsigned int row =100){
                this->row=row;
                this->col=col;
            }
            void post(unsigned int ,unsigned int , enum ariel::Direction, const std::string &);
            static std::string read(unsigned int row, unsigned int col, enum ariel::Direction, int length);
            static std::string show();


    };




}