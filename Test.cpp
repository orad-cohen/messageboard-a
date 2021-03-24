#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;



TEST_CASE("Post than read"){
    Board board;
    board.post(50,50,Direction::Horizontal,"hello world");
    //basic reads
    CHECK(board.read(50,50,Direction::Horizontal,12)==string("hello world"));
    CHECK(board.read(50,50,Direction::Horizontal,5)==string("hello"));
    CHECK(board.read(50,49,Direction::Horizontal,3)==string("_he"));
    CHECK(board.read(49,51,Direction::Vertical,4)==string("_e__"));
    //checking vertical post
    board.post(47,52,Direction::Vertical,"testing");
    CHECK(board.read(50,50,Direction::Horizontal,5)==string("hetlo"));    
    CHECK(board.read(48,52,Direction::Vertical,3)==string("sti"));
    //check overwrites
    board.post(51,49,Direction::Horizontal,"snowman");
    CHECK(board.read(49,50,Direction::Vertical,5)==string("_hn__"));
    CHECK(board.read(47,52,Direction::Vertical,8)==string("testwng_"));
    //double check overwrites
    board.post(49,49,Direction::Horizontal,"crossword");
    CHECK(board.read(47,53,Direction::Vertical,4)==string("__si"));
    CHECK(board.read(48,54,Direction::Vertical,5)==string("_woa_"));
    CHECK(board.read(49,55,Direction::Vertical,5)==string("_o n_"));
    
    board.post(50,47,Direction::Horizontal,"Computer");
    CHECK(board.read(50,47,Direction::Horizontal,13)==string("Computer world"));
    CHECK(board.read(47,52,Direction::Vertical,8)==string("testwng_"));
    
    board.post(53,50,Direction::Horizontal,"science");
    CHECK(board.read(47,52,Direction::Vertical,8)==string("testwni_"));
    CHECK(board.read(49,50,Direction::Vertical,5)==string("rpn_s"));
    
    board.post(48,54,Direction::Vertical,"election");
    CHECK(board.read(51,51,Direction::Horizontal,5)==string("owmcn"));
    CHECK(board.read(51,52,Direction::Horizontal,4)==string("_n_t"));
    CHECK(board.read(49,49,Direction::Horizontal,9)==string("crosslord"));
    CHECK(board.read(47,55,Direction::Horizontal,7)==string("o_n c__"));
    CHECK(board.read(47,56,Direction::Horizontal,5)==string("_rw__e"));
    CHECK(board.read(50,50,Direction::Horizontal,5)==string("putee"));

}
